#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int N, M;

	cin >> T;

	int D[30][30] = { 0, };

	for (int i = 1; i < 30; i++) {
		D[1][i] = i;
		D[i][i] = 1;
	}

	for (int i = 2; i < 30; i++) {		// 0 < N <= M < 30이므로 2부터 시작
		for (int j = 2; j < 30; j++) {
			D[i][j] = D[i][j - 1] + D[i - 1][j - 1];
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		cout << D[N][M] << "\n";
	}

	return 0;
}