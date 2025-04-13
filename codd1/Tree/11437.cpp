#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: 노드의 개수, M: 공통 조상을 알고싶은 쌍의 개수
	cin >> N;

	vector<vector<int>> tree(N + 1);
	
	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	// BFS로 탐색해 부모 노드와 깊이 저장
	vector<int> parent(N + 1);			// index의 부모 노드
	vector<int> depth(N + 1, 1);		// 깊이 (1부터 시작)

	vector<bool> visited(N + 1, false);
	queue<int> q;

	q.push(1);
	visited[1] = true;
	int front = q.front();

	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int i = 0; i < tree[front].size(); i++) {
			if (visited[tree[front][i]] == false) {
				q.push(tree[front][i]);
				visited[tree[front][i]] = true;

				parent[tree[front][i]] = front;				// 부모 노드 저장
				depth[tree[front][i]] = depth[front] + 1;	// 트리에서의 깊이 저장 (부모 노드의 깊이 + 1)
			}
		}
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;

		while (depth[node1] != depth[node2]) {		// 두 노드의 깊이가 다른 경우, 더 깊은 노드의 노드를 부모 노드로 올려주면서 같은 높이로 맞춤
			if (depth[node1] < depth[node2]) {
				node2 = parent[node2];
			}
			else {
				node1 = parent[node1];
			}
		}

		if (node1 == node2) {		// 바로 같은 노드를 찾으면 최소 공통 조상 출력
			cout << node1 << "\n";
		}
		else {		// 아니라면 동시에 부모 노드로 올라가면서 두 노드가 같은 노드가 될 때까지 반복
			while (node1 != node2) {
				node1 = parent[node1];
				node2 = parent[node2];

				if (node1 == node2) {
					cout << node1 << "\n";
					break;
				}
			}
		}
	}

	return 0;
}