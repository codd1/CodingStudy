#include <iostream>

#define MOD 1000000007

using namespace std;

long long dp[101][101][101];		// dp[N][L][R] = N개의 빌딩이 있고, 왼쪽에서 L개, 오른쪽에서 R개가 보일 때 가능한 경우의 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L, R;
	cin >> N >> L >> R;

	dp[1][1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int k = 1; k <= R; k++) {
				if (j == 1 && k == 1) {		// 건물의 갯수가 1 초과일 경우에는 왼쪽, 오른쪽 두 쪽에서 건물이 1개씩만 보일 수 없기 때문에 0으로 둔다.
					continue;
				}

				// overflow 방지를 위해 덧셈에서도 mod 연산
				dp[i][j][k] = ((dp[i - 1][j - 1][k] % MOD) + (dp[i - 1][j][k - 1] % MOD) + (((dp[i - 1][j][k] * (i - 2)) % MOD))) % MOD;
			}
		}
	}

	cout << dp[N][L][R] % MOD;

	return 0;
}