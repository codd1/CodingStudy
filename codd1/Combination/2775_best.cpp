#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;		// TC 개수
	int k, n;

	cin >> T;

	int D[15][15] = { 0, };

	for (int i = 1; i < 15; i++) {
		D[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			// "a층의 b호에 살려면 a-1층의 1호부터 b호까지 사람들의 수 합만큼 데려와 살아야한다."
			D[i][j] = D[i - 1][j] + D[i][j - 1];		// 모범답안

			/*
				D[1][3] = D[0][3] + D[1][2] = 3 + 3 = 6
				D[1][2]에 아래 층의 더 추가해야하는 값을 더해주기만 하면 된다.
			*/
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> k >> n;

		cout << D[k][n] << "\n";
	}

	return 0;
}