#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int D[11][11] = { 0, };

	for (int i = 0; i <= 10; i++) {
		D[i][1] = i;		// i개 중 1개를 뽑는 경우의 수는 i개
		D[i][0] = 1;		// i개 중 0개를 뽑는 경우의 수는 1개 (아무것도 안 뽑는 경우)
		D[i][i] = 1;		// i개 중 i개를 뽑는 경우의 수는 1개 (모두 뽑는 경우)
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];	// 조합 점화식
		}
	}

	cout << D[N][K];

	return 0;
}