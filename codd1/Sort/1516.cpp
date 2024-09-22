#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 건물 종류 수
	cin >> N;

	// 위상정렬 (topology sort)
	vector<int> build_time(N + 1);			// 건물 짓는 시간
	vector<int> indegree(N + 1, 0);			// 진입 차수 (자기 자신을 가리키는 엣지의 개수)
	vector<vector<int>> building(N + 1);	// 건물 건설 순서 (2차원 벡터로 그래프 표현)
	vector<int> answer(N + 1, 0);			// 정답 (출력용)

	int time;		// 건물 짓는 시간
	int previous;	// 먼저 지어야하는 건물 번호
	for (int i = 1; i <= N; i++) {
		cin >> time >> previous;
		build_time[i] = time;

		if (previous == -1) {	// 먼저 지어야하는 건물이 없다면
			continue;
		}

		while (previous != -1) {	// 먼저 지어야하는 건물이 있다면 -1이 나올 때까지 반복
			building[previous].push_back(i);
			indegree[i]++;

			cin >> previous;
		}
	}

	queue<int> q;
	int front;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {		// 진입 차수가 0인 경우만
			q.push(i);				// 큐에 삽입
		}
	}

	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int i = 0; i < building[front].size(); i++) {
			indegree[building[front][i]]--;		// 방문했다면 진입 차수--

			// building[front][i]는 현재 접근한 노드의 다음노드 (먼저 건설해야하는 건물 front, 그 다음에 오는 건물 [front][i]
			answer[building[front][i]] = max(answer[building[front][i]], answer[front] + build_time[front]);

			if (indegree[building[front][i]] == 0) {	// 진입 차수가 0이 되면 큐에 삽입
				q.push(building[front][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		answer[i] += build_time[i];		// 마지막으로 자기 건물 짓는데 걸리는 시간을 더한다.
		cout << answer[i] << "\n";
	}

	return 0;
}