#include <iostream>

#define MOD 1000000007

using namespace std;

long long dp[101][101][101];		// dp[N][L][R] = N���� ������ �ְ�, ���ʿ��� L��, �����ʿ��� R���� ���� �� ������ ����� ��

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
				if (j == 1 && k == 1) {		// �ǹ��� ������ 1 �ʰ��� ��쿡�� ����, ������ �� �ʿ��� �ǹ��� 1������ ���� �� ���� ������ 0���� �д�.
					continue;
				}

				// overflow ������ ���� ���������� mod ����
				dp[i][j][k] = ((dp[i - 1][j - 1][k] % MOD) + (dp[i - 1][j][k - 1] % MOD) + (((dp[i - 1][j][k] * (i - 2)) % MOD))) % MOD;
			}
		}
	}

	cout << dp[N][L][R] % MOD;

	return 0;
}