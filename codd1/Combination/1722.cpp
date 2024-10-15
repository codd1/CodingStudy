#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// N���� ��
	cin >> N;

	vector<long> vecN(N + 1);
	vector<long> factorial(N + 1, 1);

	int type;

	cin >> type;

	for (int i = 1; i <= N; i++) {
		vecN[i] = i;		// 1, 2, 3, ..., N

		factorial[i] = factorial[i - 1] * i;
	}

	long K;

	if (type == 1) {	// K��° ���� ���
		cin >> K;

		long count = 1;

		for (int i = 0; i < N; i++) {
			while (K > factorial[N - i - 1] * count) {	// K�� ���� �ڸ� - 1���� ���� �� �ִ� ����� ���� ��
				count++;								// K�� �� �۾��� ������ count++
			}

			cout << vecN[count] << " ";

			K = K - (factorial[N - i - 1] * (count - 1));		// K �� ������Ʈ

			vecN.erase(vecN.begin() + count);		// �������� ����� �� ����
			count = 1;
		}
	}
	else if (type == 2) {	// �־��� ������ �� ��° �������� ���
		vector<int> input(N);
		K = 1;		// K�� �⺻�� = 1

		for (int i = 0; i < N; i++) {
			cin >> input[i];

			long count = 1;

			if (vecN[count] != input[i]) {			// ���� �ڸ����� ���ڸ� Ȯ���ϰ�
				while (vecN[count] < input[i]) {	// �ش� ���ں��� �� ���� �� �̻��� ���� ������ ī��Ʈ
					count++;
				}

				K = K + factorial[N - i - 1] * (count - 1);		// K �� ������Ʈ
			}

			vecN.erase(vecN.begin() + count);		// �������� ����� �� ����
		}

		cout << K;
	}

	return 0;
}