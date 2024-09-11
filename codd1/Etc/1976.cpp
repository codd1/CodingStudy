#include <iostream>
#include <vector>

using namespace std;

int find_func(vector<int>& nodes, int num) {
	if (nodes[num] != num) {
		return find_func(nodes, nodes[num]);
	}
	else {
		return num;
	}
}

void union_func(vector<int>& nodes, int a, int b) {
	a = find_func(nodes, a);
	b = find_func(nodes, b);

	if (a != b) {
		nodes[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;	// N: ������ ��, M: ���� ��ȹ�� ���� ���õ��� ��
	cin >> N >> M;

	vector<int> nodes(N + 1);		// ���Ͽ� ���ε�
	vector<vector<int>> travel(N + 1, vector<int>(N + 1));	// ������ ���� ���� (N*N)

	for (int i = 1; i <= N; i++) {
		nodes[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> travel[i][j];

			if (travel[i][j] == 1) {	// ����� ������ ���
				union_func(nodes, i, j);
			}
		}
	}

	vector<int> plan(M);	// ���� ��ȹ(���)
	bool isYES = true;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> plan[i];

		// ���õ��� ��� ����Ǿ� �ִ��� Ȯ�� (��ǥ ��尡 ������ Ȯ��)
		if (i >= 1 && find_func(nodes, nodes[plan[i]]) != find_func(nodes, nodes[plan[i - 1]])) {
			isYES = false;
			break;
		}
	}

	if (isYES) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}