#include <iostream>
#include <vector>
#include <queue>
#include <climits>		// INT_MAX
#include <algorithm>	// min_element

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;	// V: ����� ����, E: ������ ����, K: ��� ����� ��ȣ
	cin >> V >> E >> K;

	int INF = INT_MAX;
	vector<vector<pair<int, int>>> nodes(V + 1);
	vector<int> distance(V + 1, INF);	// ��� ����� �ִ� �Ÿ��� ū ������ �ʱ�ȭ (�������� ����ġ�� 10 ���϶�� �����Ƿ� 11�� ����)
	vector<bool> visited(V + 1, false);

	distance[K] = 0;	// ���� ���� �Ÿ��� 0

	int u, v, w;	// u���� v�� ���� ����ġ w�� ����
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		nodes[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	// pair<int,int>�� ù ��° ��Ҹ� �������� ���� �������� ���� (ù ��° ��Ұ� ���� ��� �� ��° ��ҷ� ��)

	q.push(make_pair(0, K));	// ù ��° ��Ҹ� �������� ���ϱ� ������ ����ġ�� first ������ ����
	pair<int,int> top = q.top();

	while (!q.empty()) {
		top = q.top();
		q.pop();

		if (visited[top.second] == false) {
			for (int j = 0; j < nodes[top.second].size(); j++) {
				// min(���� ����� �ִ� �Ÿ� �迭�� �� + ���� ����ġ, ���� ����� �ִ� �Ÿ� �迭�� ��)
				distance[nodes[top.second][j].first] = std::min(distance[top.second] + nodes[top.second][j].second, distance[nodes[top.second][j].first]);
				q.push(make_pair(distance[nodes[top.second][j].first], nodes[top.second][j].first));
			}
		}

		visited[top.second] = true;
	}

	for (int i = 1; i <= V; i++) {
		if (distance[i] == INF) {	// ���� ��忡�� �湮�� �Ұ����� ���
			cout << "INF" << "\n";
		}
		else {
			cout << distance[i] << "\n";
		}
	}

	return 0;
}