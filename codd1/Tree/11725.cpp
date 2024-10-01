#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& tree, vector<int>& parent, vector<bool>& visited, int num) {
	visited[num] = true;

	for (int i = 0; i < tree[num].size(); i++) {
		if (visited[tree[num][i]] == false) {
			parent[tree[num][i]] = num;		// �θ� ��� ����
			DFS(tree, parent, visited, tree[num][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;			// ����� ����
	cin >> N;

	vector<vector<int>> tree(N + 1);	// ��������Ʈ �̿�

	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;
		
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	// DFS �̿�
	vector<bool> visited(N + 1, false);
	vector<int> parent(N + 1);

	DFS(tree, parent, visited, 1);		// Ʈ���� ��Ʈ�� 1�̶�� �����������Ƿ� 1���� ����

	for (int i = 2; i <= N; i++) {		// ����� 2���� ���
		cout << parent[i] << "\n";
	}

	return 0;
}