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
		D[i][1] = i;		// i�� �� 1���� �̴� ����� ���� i��
		D[i][0] = 1;		// i�� �� 0���� �̴� ����� ���� 1�� (�ƹ��͵� �� �̴� ���)
		D[i][i] = 1;		// i�� �� i���� �̴� ����� ���� 1�� (��� �̴� ���)
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];	// ���� ��ȭ��
		}
	}

	cout << D[N][K];

	return 0;
}