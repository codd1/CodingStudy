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
			for (int k = 1; k <= j; k++) {
				D[i][j] += D[i - 1][k];		// "a���� bȣ�� ����� a-1���� 1ȣ���� bȣ���� ������� �� �ո�ŭ ������ ��ƾ��Ѵ�."
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> k >> n;

		cout << D[k][n] << "\n";
	}

	return 0;
}