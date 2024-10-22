#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];		// dp[i][j]일 때, i, j의 위치를 오른쪽 아래 꼭짓점으로 정하고, 해당 자리에서 그릴 수 있는 가장 큰 정사각형 "변"의 길이

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;		// n*m 크기의 배열
	cin >> n >> m;

	char c;			// 공백 없는 입력이 있기 때문에 char 변수 선언
	int max = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			dp[i][j] = c - '0';		// char로 받아서 int형식으로 변환
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == 1) {		// 배열의 값이 1일 경우,
				// 대각선, 위쪽, 왼쪽 중 가장 작은 값에 1을 더한다.
				// 즉, 대각선, 위쪽, 왼쪽 값이 모두 같아야 기존의 값보다 커지게 될 수 있다. (각각 1,1,1이고 현재 위치가 1이라면 더 큰 정사각형 2가 됨)
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;

				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
		}
	}

	cout << max * max;

	return 0;
}