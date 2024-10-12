#include <iostream>
#include <vector>
#include <queue>
#include <cmath>	// pow()

using namespace std;

int parent[21][100001];		// P[K][N] = N번 노드의 2^K번째 부모의 노드 번호

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<vector<int>> tree(N + 1);
	
	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	
	vector<int> depth(N + 1, 0);
	vector<bool> visited(N + 1, false);
	queue<int> q;

	q.push(1);
	visited[1] = true;

	int front = q.front();
	int max_depth = 0;

	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int i = 0; i < tree[front].size(); i++) {
			if (visited[tree[front][i]] == false) {
				q.push(tree[front][i]);
				visited[tree[front][i]] = true;

				parent[0][tree[front][i]] = front;		// 부모 노드 저장
				depth[tree[front][i]] = depth[parent[0][tree[front][i]]] + 1;	// 깊이 저장

				if (depth[tree[front][i]] > max_depth) {
					max_depth = depth[tree[front][i]];
				}
			}
		}
	}

	int K = 1;
	for (; pow(2, K) <= max_depth; K++) {
		for (int i = 1; i <= N; i++) {
			parent[K][i] = parent[K - 1][parent[K - 1][i]];		// 부모 노드 배열의 점화식
		}
	}
	K--;		// 반복문이 종료되면서 마지막에 K++ 하게되므로 다시 K-- 해줌

	cin >> M;

	int k = 0;		// 2^k에서 계산될 k
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;

		while (depth[node1] != depth[node2]) {
			for (k = 0; pow(2, k) <= abs(depth[node1] - depth[node2]); k++) {
				// abs(): 절댓값을 계산해 리턴해주는 함수
			}
			k--;

			if (depth[node1] < depth[node2]) {	// node2의 깊이가 더 깊은 경우
				node2 = parent[k][node2];
			}
			else {
				node1 = parent[k][node1];
			}
		}

		if (node1 == node2) {		// 바로 공통 조상을 찾은 경우 출력
			cout << node1 << "\n";
		}
		else {		// 최소 공통 조상 찾기
			for (int i = K; i >= 0 && node1 != node2; i--) {	// 11437번 문제와 달리 한 단계씩이 아니라 2^K 단위로 점프하면서 찾는다.
				if (parent[i][node1] != parent[i][node2]) {
					node1 = parent[i][node1];
					node2 = parent[i][node2];
				}
			}

			if (node1 == node2) {			// 같은 노드라면 그대로 출력
				cout << node1 << "\n";
			}
			else {							// 다른 노드라면 그 바로 위의 부모 노드가 최소 공통 조상이 된다.
				cout << parent[0][node1] << "\n";
			}
		}
	}

	return 0;
}