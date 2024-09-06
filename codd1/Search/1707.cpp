#include <iostream>
#include <vector>

using namespace std;

// 이분 그래프: 각 집합에 속한 노드끼리 서로 인접하지 않는 두 집합으로 그래프의 노드를 나눌 수 있는 그래프

void DFS(vector<vector<int>> nodes, vector<int>& set, vector<bool>& visited, int num, bool& isCycle) {
	int nextNode;		// 다음 노드 (참고: 현재 노드는 num)

	visited[num] = true;

	for (int i = 0; i < nodes[num].size(); i++) {
		nextNode = nodes[num][i];
		if (visited[nextNode] == false) {
			set[nextNode] = (set[num] + 1) % 2;		// 인접한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리
													// 차례대로 집합 배열에 A, B, A, B 순서대로 넣는다고 생각

			DFS(nodes, set, visited, nextNode, isCycle);
		}
		else if (set[num] == set[nextNode]) {
			isCycle = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;		// 테스트 케이스 개수 K
	int V, E;	// 노드 개수 V, 엣지 개수 E

	cin >> K;

	vector<vector<int>> nodes;		// 인접리스트
	vector<int> set;		// 이분 그래프 집합
	vector<bool> visited;	// 방문 배열
	bool isCycle = true;	// 사이클이 있는지? (있다면 이분 그래프 X)

	int node1, node2;	// 입력용 변수
	for (int i = 0; i < K; i++) {
		cin >> V >> E;

		// 벡터 크기, 값 초기화
		isCycle = true;
		nodes.resize(V + 1);
		set.resize(V + 1);
		visited.resize(V + 1);

		for (int j = 1; j <= E; j++) {
			cin >> node1 >> node2;

			nodes[node1].push_back(node2);		// 인접리스트 구현
			nodes[node2].push_back(node1);
		}

		for (int j = 1; j <= V; j++) {
			if (isCycle) {
				DFS(nodes, set, visited, j, isCycle);
			}
			else {
				break;		// 사이클이 있는 경우, 바로 종료
			}
		}

		if (isCycle) {
			cout << "YES" << "\n";		// 이분 그래프
		}
		else {
			cout << "NO" << "\n";		// 이분 그래프 아님.
		}

		// 초기화
		for (int j = 0; j <= V; j++) {
			nodes[j].clear();
			visited[j] = false;
			set[j] = 0;
		}
	}

	return 0;
}