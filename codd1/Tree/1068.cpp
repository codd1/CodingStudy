#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& tree, vector<bool>& visited, int num, int& count, int be_deleted_node) {
	visited[num] = true;

	if (num == be_deleted_node) {		// DFS이므로 아래 for문 내의 if문에서 바로 return 하는게 아니라 여기서 return
		return;
	}

	for (int i = 0; i < tree[num].size(); i++) {
		if (visited[tree[num][i]] == false) {
			if (tree[num][i] == be_deleted_node) {		// 선택된 노드가 삭제될 노드라면
				if (tree[num].size() == 1) {	// 하지만 삭제될 노드 말고 다른 노드가 없다면 부모 노드가 리프 노드가 되므로
					count++;					// 리프 노드 카운트
				}
			}

			DFS(tree, visited, tree[num][i], count, be_deleted_node);
		}
	}

	if (tree[num].size() == 0) {		// 연결된 노드(=자식 노드)가 없다면 리프 노드 카운트
		count++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 트리의 노드 개수
	cin >> N;

	vector<vector<int>> tree(N);
	vector<bool> visited(N, false);
	int count = 0;		// 리프 노드의 개수

	int parent;
	int start_node = 0;
	for (int child = 0; child < N; child++) {
		cin >> parent;

		if (parent == -1) {		// 만약 부모가 없다면(루트) -1이 주어진다.
			start_node = child;
			continue;
		}

		tree[parent].push_back(child);
	}

	int be_deleted_node;		// 삭제될 노드
	cin >> be_deleted_node;

	DFS(tree, visited, start_node, count, be_deleted_node);

	cout << count << "\n";

	return 0;
}