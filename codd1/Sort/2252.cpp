#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, M;	// N: ��� ����, M: ���� ����
	cin >> N >> M;

	vector<int> indegree(N + 1, 0);
	vector<vector<int>> student(N + 1);

	int A, B;		// Ű�� ���� �� �л� A, B (�л� A�� �л� B �տ� ���� �Ѵ�)
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		student[A].push_back(B);
		indegree[B]++;
	}

	queue<int> q;
	int front;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();
		cout << front << " ";	// pop �Ǵ� ������� ��� (��, ���� ������� ���)

		for (int i = 0; i < student[front].size(); i++) {
			indegree[student[front][i]]--;		// �湮������ indegree--
			
			if (indegree[student[front][i]] == 0) {
				q.push(student[front][i]);
			}
		}
	}

	return 0;
}