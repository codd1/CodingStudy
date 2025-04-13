#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> dist[1001];		// ���ô� �ִ� 1000��, �⺻ �������� ����

int main() {
	int n, m, k;	// n: ���� ����, m: ������ ��, k: k��° �ִ� ��� ���ϱ�
	cin >> n >> m >> k;

	vector <vector<pair<int, int>>> nodes(n + 1);

	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;

		nodes[start].push_back(make_pair(end, cost));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	// �������� ����

	// ���� ���ð� 1�� ����
	dist[1].push(0);
	q.push(make_pair(0, 1));
	pair<int,int> top = q.top();

	while (!q.empty()) {
		top = q.top();
		q.pop();

		for (int i = 0; i < nodes[top.second].size(); i++) {
			if (dist[nodes[top.second][i].first].size() < k) {	// distance[����� ���]�� ũ�Ⱑ k���� �۴ٸ� ���ο� ��� �׳� �߰�
				dist[nodes[top.second][i].first].push(top.first + nodes[top.second][i].second);
				q.push(make_pair(top.first + nodes[top.second][i].second, nodes[top.second][i].first));
			}
			// distance[����� ���]�� ũ�Ⱑ k�̸鼭, distance[����� ���]�� �ִ� ��ο� ������ �� �ű� ��ΰ� �� �۴ٸ�
			else if (dist[nodes[top.second][i].first].top() > top.first + nodes[top.second][i].second) {
				dist[nodes[top.second][i].first].pop();		// ������ �ִ� �Ÿ� ��θ� �����ϰ�
				dist[nodes[top.second][i].first].push(top.first + nodes[top.second][i].second);	// �� ���� ��� ������Ʈ
				q.push(make_pair(top.first + nodes[top.second][i].second, nodes[top.second][i].first));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {	// ũ�Ⱑ k���� �۴ٸ� k��° ��ΰ� �������� �ʴ� ���̹Ƿ� -1 ���
			cout << -1 << "\n";
		}
		else {
			cout << dist[i].top() << "\n";	// top�� ���� ū ��ΰ� ���Ƿ�(k��° ���) top ���
		}
	}

	return 0;
}