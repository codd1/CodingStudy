#include <iostream>
#include <vector>
#include <climits>	// INT_MAX
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: ������ ����, M: ������ ����
	cin >> N >> M;

	int INF = INT_MAX;
	vector<vector<pair<int, int>>> nodes(N + 1);
	vector<int> distance(N + 1, INF);
	
	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;

		nodes[start].push_back(make_pair(end, cost));
	}

	cin >> start >> end;
	distance[start] = 0;

	// ���ͽ�Ʈ��

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;	// first ���� �������� ���� (�⺻: ��������)
	vector<bool> visited(N + 1, false);

	q.push(make_pair(0, start));	// ��������� ����
	pair<int,int> top = q.top();

	while (!q.empty()) {
		top = q.top();
		q.pop();

		if (visited[top.second] == false) {
			for (int i = 0; i < nodes[top.second].size(); i++) {
				// min(���� ����� �ִ� �Ÿ� �迭�� �� + ���� ����ġ, ���� ����� �ִ� �Ÿ� �迭�� ��)
				distance[nodes[top.second][i].first] = min(distance[top.second] + nodes[top.second][i].second, distance[nodes[top.second][i].first]);

				q.push(make_pair(distance[nodes[top.second][i].first], nodes[top.second][i].first));
			}
		}

		visited[top.second] = true;
	}

	cout << distance[end] << "\n";
	
	return 0;
}