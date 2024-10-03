#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& tree, vector<bool>& visited, int num, int& count, int be_deleted_node) {
	visited[num] = true;

	if (num == be_deleted_node) {		// DFS�̹Ƿ� �Ʒ� for�� ���� if������ �ٷ� return �ϴ°� �ƴ϶� ���⼭ return
		return;
	}

	for (int i = 0; i < tree[num].size(); i++) {
		if (visited[tree[num][i]] == false) {
			if (tree[num][i] == be_deleted_node) {		// ���õ� ��尡 ������ �����
				if (tree[num].size() == 1) {	// ������ ������ ��� ���� �ٸ� ��尡 ���ٸ� �θ� ��尡 ���� ��尡 �ǹǷ�
					count++;					// ���� ��� ī��Ʈ
				}
			}

			DFS(tree, visited, tree[num][i], count, be_deleted_node);
		}
	}

	if (tree[num].size() == 0) {		// ����� ���(=�ڽ� ���)�� ���ٸ� ���� ��� ī��Ʈ
		count++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// Ʈ���� ��� ����
	cin >> N;

	vector<vector<int>> tree(N);
	vector<bool> visited(N, false);
	int count = 0;		// ���� ����� ����

	int parent;
	int start_node = 0;
	for (int child = 0; child < N; child++) {
		cin >> parent;

		if (parent == -1) {		// ���� �θ� ���ٸ�(��Ʈ) -1�� �־�����.
			start_node = child;
			continue;
		}

		tree[parent].push_back(child);
	}

	int be_deleted_node;		// ������ ���
	cin >> be_deleted_node;

	DFS(tree, visited, start_node, count, be_deleted_node);

	cout << count << "\n";

	return 0;
}