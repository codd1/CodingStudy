#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: ����� ����, M: ���� ������ �˰���� ���� ����
	cin >> N;

	vector<vector<int>> tree(N + 1);
	
	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	// BFS�� Ž���� �θ� ���� ���� ����
	vector<int> parent(N + 1);			// index�� �θ� ���
	vector<int> depth(N + 1, 1);		// ���� (1���� ����)

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

				parent[tree[front][i]] = front;				// �θ� ��� ����
				depth[tree[front][i]] = depth[front] + 1;	// Ʈ�������� ���� ���� (�θ� ����� ���� + 1)
			}
		}
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;

		while (depth[node1] != depth[node2]) {		// �� ����� ���̰� �ٸ� ���, �� ���� ����� ��带 �θ� ���� �÷��ָ鼭 ���� ���̷� ����
			if (depth[node1] < depth[node2]) {
				node2 = parent[node2];
			}
			else {
				node1 = parent[node1];
			}
		}

		if (node1 == node2) {		// �ٷ� ���� ��带 ã���� �ּ� ���� ���� ���
			cout << node1 << "\n";
		}
		else {		// �ƴ϶�� ���ÿ� �θ� ���� �ö󰡸鼭 �� ��尡 ���� ��尡 �� ������ �ݺ�
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