#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;		// 도시의 개수
	int M;		// 도로의 개수
	int K;		// 거리 정보 K
	int X;		// 출발 도시의 번호 X

	cin >> N >> M >> K >> X;

	vector<vector<int>> nodes(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> distance(N + 1, 0);	// 최단 거리

	int A, B;	// 도시 A, B
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		nodes[A].push_back(B);		// 단방향 도로
	}

	queue<int> q;
	q.push(X);		// X 도시부터 출발
	visited[X] = true;
	int front = q.front();

	// BFS
	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int i = 0; i < nodes[front].size(); i++) {
			if (visited[nodes[front][i]] == false) {
				q.push(nodes[front][i]);
				visited[nodes[front][i]] = true;
				distance[nodes[front][i]] = distance[front] + 1;
			}
		}
	}

	bool isDistanceK = false;

	for (int i = 0; i <= N; i++) {
		if (distance[i] == K) {
			cout << i << endl;
			isDistanceK = true;
		}
	}

	if (isDistanceK == false) {		// 최단 거리가 K인 도시가 하나도 존재하지 않으면 -1을 출력
		cout << -1 << endl;
	}

	return 0;
}