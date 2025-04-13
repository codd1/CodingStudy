#include <iostream>
#include <vector>

using namespace std;

int find_func(vector<int>& nodes, int num) {
	if (nodes[num] != num) {	// a�� ��ǥ ��尡 �ƴ� ���,
		return find_func(nodes, nodes[num]);
	}
	else {
		return nodes[num];
	}
}

void union_func(vector<int>& nodes, int a, int b) {
	// a, b�� ��ǥ ��尡 �ƴ� ���, �� ����� ��ǥ ��带 ã�� �ö� ���� ��ǥ ��峢�� �����Ѵ�.
	// ���� ���, 4�� 6�� ��ǥ ��尡 �ƴ� ���, union(4, 6)�ϸ� 4�� ��ǥ ����� 1�� 6�� ��ǥ ��� 5�� �����Ѵ�.

	int a_main_node = find_func(nodes, a);
	int b_main_node = find_func(nodes, b);

	if (a_main_node != b_main_node) {		// ��ǥ ��尡 ���� ���� ���,
		nodes[b_main_node] = a_main_node;	// ��ǥ ��峢�� ����
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;	// n: ������ ����, m: ���� ����
	cin >> n >> m;

	vector<int> nodes(n + 1);	// 0 ~ n

	int operation;		// union or find
	int a, b;			// ���꿡 ���� ��

	for (int i = 0; i < n + 1; i++) {
		nodes[i] = i;		// ó������ ��尡 ����Ǿ����� �����Ƿ� �� ��尡 ��ǥ ���. �ڽ��� �ε��� ������ �ʱ�ȭ
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