#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& tree, vector<int>& parent, vector<bool>& visited, int num) {
	visited[num] = true;

	for (int i = 0; i < tree[num].size(); i++) {
		if (visited[tree[num][i]] == false) {
			parent[tree[num][i]] = num;		// 부모 노드 저장
			DFS(tree, parent, visited, tree[num][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;			// 노드의 개수
	cin >> N;

	vector<vector<int>> tree(N + 1);	// 인접리스트 이용

	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;
		
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	// DFS 이용
	vector<bool> visited(N + 1, false);
	vector<int> parent(N + 1);

	DFS(tree, parent, visited, 1);		// 트리의 루트가 1이라고 정해져있으므로 1부터 시작

	for (int i = 2; i <= N; i++) {		// 결과는 2부터 출력
		cout << parent[i] << "\n";
	}

	return 0;
}