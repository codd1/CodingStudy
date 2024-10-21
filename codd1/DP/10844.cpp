#include <iostream>
#include <vector>

#define MOD 1000000000

using namespace std;

int DP[101][101];		// DP[X][Y] = ���̰� X�� ��ܿ��� Y�� ����Ǵ� ����� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	DP[1][0] = 0;		// 0���� ���۵Ǵ� ���ڴ� �������� �ʱ� ������ 0�� ��� ���� �ƴ�.
	for (int i = 1; i < 10; i++) {
		DP[1][i] = 1;	// 1 ~ 9�� ��� ��
	}

	for (int i = 2; i < 101; i++) {
		DP[i][0] = DP[i - 1][1];		// N��° ���̿��� 0���� ������ ����̶��, N-1������ 1�̾�� �Ѵ�. (-1�� �ȵǱ� ����)
		DP[i][9] = DP[i - 1][8];		// N��° ���̿��� 9�� ������ ����̶��, N-1������ 8�̾�� �Ѵ�. (10�� �ȵǱ� ����)

		for (int j = 1; j <= 8; j++) {	// 1 ~ 8�� ������ ����̶�� N-1���� 1-1, 1+1 �� �� �� �� �ִ�.
			DP[i][j] = ((DP[i - 1][j - 1] % MOD) + (DP[i - 1][j + 1] % MOD) % MOD);
		}
	}

	int result = 0;
	for (int i = 0; i <= 9; i++) {
		result = ((result % MOD) + (DP[N][i] % MOD)) % MOD;		// N�ڸ� ���� 0 ~ 9�� ������ ��� �� ������ ���� ����
	}

	cout << result % MOD;

	return 0;
}