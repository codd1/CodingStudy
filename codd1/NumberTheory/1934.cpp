#include <iostream>

using namespace std;

int main() {
	int A, B, T;	// �� �ڿ��� A, B, �׽�Ʈ ���̽� ���� T

	cin >> T;

	int A_result = 0;		// A�� ���
	int B_result = 1;		// B�� ���
	int A_multiple = 2;		// A�� ���� ��
	int B_multiple = 2;		// B�� ���� ��

	for (int i = 0; i < T; i++) {
		cin >> A >> B;

		A_result = A;
		B_result = B;
		A_multiple = 2;
		B_multiple = 2;

		// �ּҰ������ ã�� ������ �ݺ�
		while (A_result != B_result) {
			if (A_result < B_result) {
				A_result = A * A_multiple;
				A_multiple++;
			}
			else {
				B_result = B * B_multiple;
				B_multiple++;
			}
		}

		cout << A_result << endl;
	}

	return 0;
}