#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>	// max_element

using namespace std;

// BFS를 별도의 함수로 구현하면 시간초과 나옴....

int main() {
	int N;		// 컴퓨터 개수 (노드)
	int M;		// 신뢰 관계 개수 (엣지)

	cin >> N >> M;

	vector<vector<int>> network(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> count(N + 1, 0);

	int A, B;	// A가 B를 신뢰한다

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		network[A].push_back(B);
	}

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);

		// BFS 구현
		q.push(i);		// 임의적으로 1번 컴퓨터부터 시작
		visited[i] = true;
		int front = q.front();

		while (!q.empty()) {
			front = q.front();
			q.pop();

			for (int i = 0; i < network[front].size(); i++) {
				if (visited[network[front][i]] == false) {
					q.push(network[front][i]);
					visited[network[front][i]] = true;
					count[network[front][i]]++;		// 탐색되는 노드들의 count++
				}
			}
		}
	}

	int max = *max_element(count.begin(), count.end());

	for (int i = 1; i <= N; i++) {
		if (count[i] == max) {
			cout << i << " ";
		}
	}

	return 0;
}