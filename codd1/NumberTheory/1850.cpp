#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	long long A, B;

	cin >> A >> B;

	long long operand1 = max(A, B);	// �ǿ�����1
	long long operand2 = min(A, B);	// �ǿ�����2
	long long result = 1;

	// ��Ŭ���� ȣ����
	while (result != 0) {
		result = operand1 % operand2;
		if (result == 0) {
			break;
		}
		operand1 = operand2;
		operand2 = result;
	}

	for (int i = 0; i < operand2; i++) {	// operand2��ŭ 1 ���
		cout << 1;
	}

	return 0;
}