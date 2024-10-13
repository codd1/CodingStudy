#include <iostream>

using namespace std;

int D[1001][1001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	int mod = 10007;

	for (int i = 0; i <= 1000; i++) {
		D[i][1] = i;
		D[i][0] = 1;
		D[i][i] = 1;
	}

	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			// (A+B) % mod = ((A % mod) + (B % mod)) % mod
			// 매번 mod 해주지 않으면 오버플로우 발생 가능
			D[i][j] = ((D[i - 1][j] % mod) + (D[i - 1][j - 1] % mod)) % mod;
		}
	}

	cout << D[N][K] << "\n";

	return 0;
}