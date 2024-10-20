#include <iostream>
#include <vector>

#define MOD 10007

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<long long> DP(n + 2);

	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= n; i++) {
		DP[i] = ((DP[i - 2] % MOD) + (DP[i - 1] % MOD)) % MOD;
	}

	cout << DP[n] % MOD;

	return 0;
}