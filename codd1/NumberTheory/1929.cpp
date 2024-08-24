#include <iostream>
#include <vector>

using namespace std;

int main() {
	int M;		// M �̻�
	int N;		// N ������ �Ҽ� ã��

	cin >> M >> N;

	vector<int> prime(N + 1 , 1);	// �����佺�׳׽� ����� �̿�
	prime[0] = 0;
	prime[1] = 0;

	int multiply = 2;		// prime[i]�� ���� �� (����� ���ֱ� ����)
	int multiple = 0;		// prime[i]�� ���

	for (int i = 2; i <= N; i++) {
		if (prime[i] == 1) {	// ���� ������ ���� �ƴ϶��, (= �Ҽ� �ĺ��� �ִ� �����)
			multiple = i * multiply;
			while (multiple <= N) {		// i�� ������� ��� 0���� ǥ��
				prime[multiple] = 0;	// 0�̶�� ���� �Ҽ��� �ƴ϶�� ��
				multiple = i * multiply;
				multiply++;
			}
		}

		multiply = 2;
		multiple = 0;
	}

	for (int i = M; i <= N; i++) {
		if (prime[i] == 1) {	// 1�� �����ִ� �� = �Ҽ��� ���
			cout << i << endl;
		}
	}

	return 0;
}