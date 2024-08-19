#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;		// �迭�� ũ�� N
	int k;		// ���� B�� �ε��� ��

	cin >> N >> k;

	int start = 1;
	int end = k;
	int median = (1 + k) / 2;		// ���� Ž���� ���� �߾Ӱ�

	int sum = 0;		// median���� �۰ų� ���� ���� ����


	while (start <= end) {
		median = (start + end) / 2;
		sum = 0;

		for (int i = 1; i <= N; i++) {
			sum += min(median / i, N);		// count�� median�� �� ���� ù ��° ��(1,2,3)���� ���� ���� �����̴�. (���������� 1+2+3=6)
											// ������ �� ���� ũ�Ⱑ N�̹Ƿ� N���� Ŭ ��� N ������ ���Ѵ�.
		}

		if (k > sum) {		// �߾Ӱ����� ���� ���� ����(sum)�� k���� ������,
			start = median + 1;
		}
		else {				// �߾Ӱ����� ���� ���� ������ k���� ũ�ų� ������,
			end = median - 1;
		}
	}

	cout << start << endl;

	return 0;
}