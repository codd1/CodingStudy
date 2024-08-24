#include <iostream>
#include <vector>
#include <cmath>	// sqrt, pow

using namespace std;

int main() {
	long long A, B;		// A���� ũ�ų� ���� B���� �۰ų� ���� '���� �Ҽ�' ���ϱ�
	int count = 0;	// '���� �Ҽ�' ����

	cin >> A >> B;

	long long square_root = sqrt(static_cast<long long>(B));	// B�� ������
	vector<int> almost_prime(square_root + 1, 1);				// ���� �Ҽ�
	almost_prime[0] = 0;
	almost_prime[1] = 0;

	int multiply = 2;		// i�� ���� ��
	int multiple = 0;		// i�� ���
	for (int i = 2; i <= square_root; i++) {	// ������ 1~10^14�� ũ�� ������ "������"�� ���� ���
		if (almost_prime[i] == 1) {		// i�� �Ҽ� �ĺ��� �ִ� ���̶��
			multiple = i * multiply;
			while (multiple <= square_root) {	// i�� ������� ��� ���� 0���� �����. (�Ҽ��� �ƴ϶�� ��)
				almost_prime[multiple] = 0;
				multiply++;
				multiple = i * multiply;
			}
		}

		multiply = 2;
		multiple = 0;
	}

	multiply = 2;
	for (int i = 2; i <= square_root; i++) {
		if (almost_prime[i] == 1) {
			while (pow(i, multiply) <= B) {		// ���� ���, 10 20�� �Էµ��� �� 2^4�� '���� �Ҽ�'�ε� A <= pow <= B�� ������ �� ���
												// �׳� �Ѿ�� ������ while�� ���ǰ� �Ʒ� if�� ������ ���� �д�.
				if (A <= pow(i, multiply)) {
					count++;
				}
				multiply++;
			}
		}
		multiply = 2;
	}

	cout << count << endl;

	return 0;
}