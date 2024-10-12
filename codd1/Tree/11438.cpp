#include <iostream>
#include <vector>
#include <queue>
#include <cmath>	// pow()

using namespace std;

int parent[21][100001];		// P[K][N] = N�� ����� 2^K��° �θ��� ��� ��ȣ

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

				parent[0][tree[front][i]] = front;		// �θ� ��� ����
				depth[tree[front][i]] = depth[parent[0][tree[front][i]]] + 1;	// ���� ����

				if (depth[tree[front][i]] > max_depth) {
					max_depth = depth[tree[front][i]];
				}
			}
		}
	}

	int K = 1;
	for (; pow(2, K) <= max_depth; K++) {
		for (int i = 1; i <= N; i++) {
			parent[K][i] = parent[K - 1][parent[K - 1][i]];		// �θ� ��� �迭�� ��ȭ��
		}
	}
	K--;		// �ݺ����� ����Ǹ鼭 �������� K++ �ϰԵǹǷ� �ٽ� K-- ����

	cin >> M;

	int k = 0;		// 2^k���� ���� k
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;

		while (depth[node1] != depth[node2]) {
			for (k = 0; pow(2, k) <= abs(depth[node1] - depth[node2]); k++) {
				// abs(): ������ ����� �������ִ� �Լ�
			}
			k--;

			if (depth[node1] < depth[node2]) {	// node2�� ���̰� �� ���� ���
				node2 = parent[k][node2];
			}
			else {
				node1 = parent[k][node1];
			}
		}

		if (node1 == node2) {		// �ٷ� ���� ������ ã�� ��� ���
			cout << node1 << "\n";
		}
		else {		// �ּ� ���� ���� ã��
			for (int i = K; i >= 0 && node1 != node2; i--) {	// 11437�� ������ �޸� �� �ܰ辿�� �ƴ϶� 2^K ������ �����ϸ鼭 ã�´�.
				if (parent[i][node1] != parent[i][node2]) {
					node1 = parent[i][node1];
					node2 = parent[i][node2];
				}
			}

			if (node1 == node2) {			// ���� ����� �״�� ���
				cout << node1 << "\n";
			}
			else {							// �ٸ� ����� �� �ٷ� ���� �θ� ��尡 �ּ� ���� ������ �ȴ�.
				cout << parent[0][node1] << "\n";
			}
		}
	}

	return 0;
}