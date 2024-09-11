#include <iostream>
#include <vector>

using namespace std;

int find_func(vector<int>& nodes, int num) {
	if (nodes[num] != num) {	// a가 대표 노드가 아닐 경우,
		return find_func(nodes, nodes[num]);
	}
	else {
		return nodes[num];
	}
}

void union_func(vector<int>& nodes, int a, int b) {
	// a, b가 대표 노드가 아닐 경우, 각 노드의 대표 노드를 찾아 올라간 다음 대표 노드끼리 연결한다.
	// 예를 들어, 4와 6이 대표 노드가 아닐 경우, union(4, 6)하면 4의 대표 노드인 1에 6의 대표 노드 5를 연결한다.

	int a_main_node = find_func(nodes, a);
	int b_main_node = find_func(nodes, b);

	if (a_main_node != b_main_node) {		// 대표 노드가 같지 않을 경우,
		nodes[b_main_node] = a_main_node;	// 대표 노드끼리 연결
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// n: 원소의 갯수, m: 질의 갯수
	cin >> n >> m;

	vector<int> nodes(n + 1);	// 0 ~ n

	int operation;		// union or find
	int a, b;			// 연산에 사용될 값

	for (int i = 0; i < n + 1; i++) {
		nodes[i] = i;		// 처음에는 노드가 연결되어있지 않으므로 각 노드가 대표 노드. 자신의 인덱스 값으로 초기화
	}

	for (int i = 0; i < m; i++) {
		cin >> operation >> a >> b;

		if (operation == 0) {		// union
			union_func(nodes, a, b);
		}
		else if (operation == 1) {	// find
			a = find_func(nodes, a);
			b = find_func(nodes, b);

			if (a == b) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		else {
			continue;
		}
	}

	return 0;
}