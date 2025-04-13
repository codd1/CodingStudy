#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;		// TC ����
	int k, n;

	cin >> T;

	int D[15][15] = { 0, };

	for (int i = 1; i < 15; i++) {
		D[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			// "a���� bȣ�� ����� a-1���� 1ȣ���� bȣ���� ������� �� �ո�ŭ ������ ��ƾ��Ѵ�."
			D[i][j] = D[i - 1][j] + D[i][j - 1];		// ������

			/*
				D[1][3] = D[0][3] + D[1][2] = 3 + 3 = 6
				D[1][2]�� �Ʒ� ���� �� �߰��ؾ��ϴ� ���� �����ֱ⸸ �ϸ� �ȴ�.
			*/
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> k >> n;

		cout << D[k][n] << "\n";
	}

	return 0;
}