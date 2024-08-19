#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;		// ������ ���� ����
	int K;		// ������� ��ġ�� ��
	int count = 0;		// K���� ����� �� �ʿ��� ���� ������ �ּڰ� = ����

	cin >> N >> K;

	vector<int> coin(N);

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	// ���� ������ ū �������� ���ʴ�� ����Ѵ�.
	for (int i = N - 1; i >= 0; i--) {
		if (coin[i] <= K) {
			while (K >= coin[i]) {
				K -= coin[i];
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}