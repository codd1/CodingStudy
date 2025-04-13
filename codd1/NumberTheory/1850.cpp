#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	long long A, B;

	cin >> A >> B;

	long long operand1 = max(A, B);	// 피연산자1
	long long operand2 = min(A, B);	// 피연산자2
	long long result = 1;

	// 유클리드 호제법
	while (result != 0) {
		result = operand1 % operand2;
		if (result == 0) {
			break;
		}
		operand1 = operand2;
		operand2 = result;
	}

	for (int i = 0; i < operand2; i++) {	// operand2만큼 1 출력
		cout << 1;
	}

	return 0;
}