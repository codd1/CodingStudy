#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, M;	// N: 노드 개수, M: 엣지 개수
	cin >> N >> M;

	vector<int> indegree(N + 1, 0);
	vector<vector<int>> student(N + 1);

	int A, B;		// 키를 비교할 두 학생 A, B (학생 A가 학생 B 앞에 서야 한다)
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
		cout << front << " ";	// pop 되는 순서대로 출력 (즉, 정렬 순서대로 출력)

		for (int i = 0; i < student[front].size(); i++) {
			indegree[student[front][i]]--;		// 방문했으니 indegree--
			
			if (indegree[student[front][i]] == 0) {
				q.push(student[front][i]);
			}
		}
	}

	return 0;
}