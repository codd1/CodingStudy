#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	// N C K (����) = N! / (N-K)! * K!

	int denominator = 1;	// �и�
	int molecule = 1;		// ����


	for (int i = 1; i <= N; i++) {		// N!
		molecule *= i;
	}

	for (int i = N - K; i >= 1; i--) {	// (N-K)!
		denominator *= i;
	}

	for (int i = 1; i <= K; i++) {		// K!
		denominator *= i;
	}

	cout << molecule / denominator;

	return 0;
}