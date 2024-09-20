#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// �ǹ� ���� ��
	cin >> N;

	// �������� (topology sort)
	vector<int> build_time(N + 1);			// �ǹ� ���� �ð�
	vector<int> indegree(N + 1, 0);			// ���� ���� (�ڱ� �ڽ��� ����Ű�� ������ ����)
	vector<vector<int>> building(N + 1);	// �ǹ� �Ǽ� ���� (2���� ���ͷ� �׷��� ǥ��)
	vector<int> answer(N + 1, 0);			// ���� (��¿�)

	int time;		// �ǹ� ���� �ð�
	int previous;	// ���� ������ϴ� �ǹ� ��ȣ
	for (int i = 1; i <= N; i++) {
		cin >> time >> previous;
		build_time[i] = time;

		if (previous == -1) {	// ���� ������ϴ� �ǹ��� ���ٸ�
			continue;
		}

		while (previous != -1) {	// ���� ������ϴ� �ǹ��� �ִٸ� -1�� ���� ������ �ݺ�
			building[previous].push_back(i);
			indegree[i]++;

			cin >> previous;
		}
	}

	queue<int> q;
	int front;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {		// ���� ������ 0�� ��츸
			q.push(i);				// ť�� ����
		}
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int i = 0; i < building[front].size(); i++) {
			indegree[building[front][i]]--;		// �湮�ߴٸ� ���� ����--

			// building[front][i]�� ���� ������ ����� ������� (���� �Ǽ��ؾ��ϴ� �ǹ� front, �� ������ ���� �ǹ� [front][i]
			answer[building[front][i]] = max(answer[building[front][i]], answer[front] + build_time[front]);

			if (indegree[building[front][i]] == 0) {	// ���� ������ 0�� �Ǹ� ť�� ����
				q.push(building[front][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		answer[i] += build_time[i];		// ���������� �ڱ� �ǹ� ���µ� �ɸ��� �ð��� ���Ѵ�.
		cout << answer[i] << "\n";
	}

	return 0;
}