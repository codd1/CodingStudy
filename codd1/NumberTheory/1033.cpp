#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// �� int -> long���� �ؾ��ϸ� ���� ó�� ��.

long gcd(long operand1, long operand2);
void DFS(vector<vector<tuple<long, long, long>>> ingredient, vector<long>& nodes, vector<bool>& visited, long num);

int main() {
	long N;
	long a, b, p, q;

	cin >> N;

	vector<vector<tuple<long, long, long>>> ingredient(N);		// Ȥ�� vector<tuple<int, int, int>> ingredient[10];
	long lcm = 1;	// �ּ� �����(least common multiple)

	for (long i = 0; i < N - 1; i++) {
		cin >> a >> b >> p >> q;

		// ��������Ʈ ����
		ingredient[a].push_back(make_tuple(b, p, q));
		ingredient[b].push_back(make_tuple(a, q, p));

		lcm = lcm * (p * q / gcd(p, q));	// p�� q�� �ּҰ����
	}

	vector<long> nodes(N, 0);		// �� ����� ��(����)
	nodes[0] = lcm;					// ������ ������(0)�� �ּҰ���� ���� ����
	vector<bool> visited(N, false);	// DFS

	DFS(ingredient, nodes, visited, 0);

	long gcd_num = nodes[0];	// �������� ���� �ִ�����
	for (long i = 1; i < N; i++) {
		gcd_num = gcd(gcd_num, nodes[i]);
	}

	for (long i = 0; i < N; i++) {
		cout << nodes[i] / gcd_num << " ";
	}

	return 0;
}

void DFS(vector<vector<tuple<long, long, long>>> ingredient, vector<long>& nodes, vector<bool>& visited, long num) {
	visited[num] = true;

	for (long i = 0; i < ingredient[num].size(); i++) {
		if (visited[get<0>(ingredient[num][i])] == false) {		// ingredient[num][i]�� tuple �� ù ��° ���Ұ� (get<0>())
			nodes[get<0>(ingredient[num][i])] = nodes[num] * get<2>(ingredient[num][i]) / get<1>(ingredient[num][i]);	// num�� ����� ��� = num�� ��尪 * get<2> / get<1>
			DFS(ingredient, nodes, visited, get<0>(ingredient[num][i]));
		}
	}
}

// ��Ŭ���� ȣ����
long gcd(long operand1, long operand2) {
	if (operand1 < operand2) {
		long temp = operand1;
		operand1 = operand2;
		operand2 = temp;
	}

	long result = 0;

	while (1) {
		result = operand1 % operand2;
		if (result == 0) {
			break;
		}
		operand1 = operand2;
		operand2 = result;
	}

	return operand2;
}