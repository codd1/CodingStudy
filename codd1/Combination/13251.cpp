#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long M, K;

	cin >> M;

	vector<long long> N(M);
	double N_sum = 0;		// 모든 조약돌의 갯수 총합

	for (int i = 0; i < M; i++) {
		cin >> N[i];

		N_sum += N[i];
	}

	cin >> K;

	double sum = 1.0;		// 각 조약돌 색별로 확률
	double result = 0.0;

	/*
		3
		5 6 7
		2

		5개 조약돌 색 뽑을 확률 = 5/18 * 4/17 = A
		6개 조약돌 색 뽑을 확률 = 6/18 * 5/17 = B
		7개 조약돌 색 뽑을 확률 = 7/18 * 6/17 = C

		result = A + B + C
	*/

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			sum *= (N[i] - j) / (N_sum - j);
		}
		
		result += sum;

		sum = 1.0;
	}

	cout.precision(16);		// 소수점 16번째 자리까지 출력

	cout << result << "\n";

	return 0;
}