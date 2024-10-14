#include <iostream>
#include <vector>

using namespace std;

long long factorial(long long num) {
	if (num <= 1) {
		return 1;
	}

	return num * factorial(num - 1);
}

long long factorial(long long N_sum, long long K) {
	int result = 1;
	for (int i = N_sum; i > N_sum - K; i--) {
		result *= i;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long M, K;

	cin >> M;

	vector<long long> N(M);

	double N_sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> N[i];

		N_sum += N[i];
	}

	cin >> K;

	N_sum = factorial(N_sum, K) / factorial(K);

	double C_sum = 0;
	for (int i = 0; i < M; i++) {
		// N[i] C k
		C_sum += factorial(N[i], K) / factorial(K);
	}

	float result = C_sum / N_sum;

	cout.precision(16);		// 소수점 16번째 자리까지 출력

	cout << C_sum / N_sum << "\n";

	return 0;
}