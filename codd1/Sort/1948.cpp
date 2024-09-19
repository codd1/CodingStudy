#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// n: ������ ����, m: ������ ����
	cin >> n >> m;

	vector<int> indegree(n + 1, 0);
	vector<vector<pair<int,int>>> road(n + 1);
	vector<vector<pair<int,int>>> reverse_road(n + 1);		// road�� ������ ������ �ݴ�
	vector<int> critical_path(n + 1, 0);	// �Ӱ� ���

	// ������ �׸��� ������� �����ϴ� �ð� ���ϱ�
	queue<int> q;
	int front;

	int start, end, time;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> time;

		road[start].push_back(make_pair(end, time));	// �������� �ҿ� �ð��� ���� �����ϱ� ���� pair ���
		reverse_road[end].push_back(make_pair(start, time));	// ������ ��������Ʈ�� ����
		indegree[end]++;
	}

	cin >> start >> end;
	q.push(start);		// ���� ���ÿ������� ����

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0 && i != q.front()) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();		// pop �Ǵ� ������� ���ĵ�

		for (int i = 0; i < road[front].size(); i++) {
			indegree[road[front][i].first]--;

			critical_path[road[front][i].first] = max(critical_path[road[front][i].first], critical_path[front] + road[front][i].second);	// ���� ������ �Ӱ� ��� �� + ���� ������ �ҿ� �ð�

			if (indegree[road[front][i].first] == 0) {
				q.push(road[front][i].first);
			}
		}
	}

	cout << critical_path[end] << "\n";		// ������ �׸��� ������� �����ϴ� �ð� ���

	// 1�е� ���� �ʰ� �޷����ϴ� ������ �� ���ϱ�
	int count = 0;
	vector<int> visited(false, 0);

	q.push(end);
	front = q.front();

	while (!q.empty()) {
		front = q.front();
		q.pop();
		count++;

		for (int i = 0; i < reverse_road[front].size(); i++) {
			if (visited[reverse_road[front][i].first] == false) {
				if (critical_path[front] == critical_path[reverse_road[front][i].first] + reverse_road[front][i].second) {
					q.push(reverse_road[front][i].first);
				}

				visited[reverse_road[front][i].first] = true;
			}
		}
	}

	cout << count << "\n";

	return 0;
}