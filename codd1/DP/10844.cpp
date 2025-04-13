#include <iostream>
#include <vector>

#define MOD 1000000000

using namespace std;

int DP[101][101];		// DP[X][Y] = 길이가 X인 계단에서 Y로 종료되는 계단의 갯수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	DP[1][0] = 0;		// 0으로 시작되는 숫자는 인정되지 않기 때문에 0은 계단 수가 아님.
	for (int i = 1; i < 10; i++) {
		DP[1][i] = 1;	// 1 ~ 9는 계단 수
	}

	for (int i = 2; i < 101; i++) {
		DP[i][0] = DP[i - 1][1];		// N번째 길이에서 0으로 끝나는 계단이라면, N-1에서는 1이어야 한다. (-1은 안되기 때문)
		DP[i][9] = DP[i - 1][8];		// N번째 길이에서 9로 끝나는 계단이라면, N-1에서는 8이어야 한다. (10은 안되기 때문)

		for (int j = 1; j <= 8; j++) {	// 1 ~ 8로 끝나는 계단이라면 N-1에서 1-1, 1+1 둘 다 될 수 있다.
			DP[i][j] = ((DP[i - 1][j - 1] % MOD) + (DP[i - 1][j + 1] % MOD) % MOD);
		}
	}

	int result = 0;
	for (int i = 0; i <= 9; i++) {
		result = ((result % MOD) + (DP[N][i] % MOD)) % MOD;		// N자리 수의 0 ~ 9로 끝나는 계단 수 갯수의 총합 저장
	}

	cout << result % MOD;

	return 0;
}