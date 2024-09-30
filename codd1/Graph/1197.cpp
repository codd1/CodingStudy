#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int find_func(vector<int>& union_find, int num) {					// find
	if (union_find[num] != num) {
		return find_func(union_find, union_find[num]);
	}
	else {
		return num;
	}
}

void union_func(vector<int>& union_find, int num1, int num2) {		// union
	num1 = find_func(union_find, num1);
	num2 = find_func(union_find, num2);

	if (num1 != num2) {
		union_find[num2] = num1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;	// V: ������ ����, E: ������ ����
	cin >> V >> E;

	vector<int> union_find(V + 1);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;	// ù ��° ��Ҹ� �������� �������� ����

	for (int i = 1; i <= V; i++) {		// ���Ͽ����ε� �迭 �ʱ�ȭ
		union_find[i] = i;
	}

	int A, B, C;	// A�� ������ B�� ������ ����ġ C�� �������� ����Ǿ�����
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;

		q.push(make_tuple(C, A, B));	// ù ��° ��Ҹ� �������� �����ϹǷ� �� �տ� ����ġ�� C�� ��
	}

	int connected_edge = 0;		// ����� ���� ���� (����� ���� ������ V - 1�� �Ǹ� ����)
	int sum = 0;
	while (connected_edge < V - 1) {
		if (find_func(union_find, get<1>(q.top())) != find_func(union_find, get<2>(q.top()))) {		// ��ǥ ��尡 ���ٸ� �� ��带 �������� �� ����Ŭ�� ���������.
			union_func(union_find, get<1>(q.top()), get<2>(q.top()));	// ����Ŭ�� ��������� �ʴ� ��常 ���� (union)
			sum += get<0>(q.top());

			connected_edge++;
		}
		q.pop();
	}

	cout << sum << "\n";

	return 0;
}