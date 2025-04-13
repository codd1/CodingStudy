#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// ★ int -> long으로 해야하만 정답 처리 됨.

long gcd(long operand1, long operand2);
void DFS(vector<vector<tuple<long, long, long>>> ingredient, vector<long>& nodes, vector<bool>& visited, long num);

int main() {
	long N;
	long a, b, p, q;

	cin >> N;

	vector<vector<tuple<long, long, long>>> ingredient(N);		// 혹은 vector<tuple<int, int, int>> ingredient[10];
	long lcm = 1;	// 최소 공배수(least common multiple)

	for (long i = 0; i < N - 1; i++) {
		cin >> a >> b >> p >> q;

		// 인접리스트 구현
		ingredient[a].push_back(make_tuple(b, p, q));
		ingredient[b].push_back(make_tuple(a, q, p));

		lcm = lcm * (p * q / gcd(p, q));	// p와 q의 최소공배수
	}

	vector<long> nodes(N, 0);		// 각 재료의 값(질량)
	nodes[0] = lcm;					// 임의의 시작점(0)에 최소공배수 값을 저장
	vector<bool> visited(N, false);	// DFS

	DFS(ingredient, nodes, visited, 0);

	long gcd_num = nodes[0];	// 마지막에 나눌 최대공약수
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
		if (visited[get<0>(ingredient[num][i])] == false) {		// ingredient[num][i]의 tuple 중 첫 번째 원소값 (get<0>())
			nodes[get<0>(ingredient[num][i])] = nodes[num] * get<2>(ingredient[num][i]) / get<1>(ingredient[num][i]);	// num과 연결된 노드 = num번 노드값 * get<2> / get<1>
			DFS(ingredient, nodes, visited, get<0>(ingredient[num][i]));
		}
	}
}

// 유클리드 호제법
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