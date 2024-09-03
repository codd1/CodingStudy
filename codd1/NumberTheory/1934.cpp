#include <iostream>

using namespace std;

int main() {
	int A, B, T;	// 두 자연수 A, B, 테스트 케이스 갯수 T

	cin >> T;

	int A_result = 0;		// A의 배수
	int B_result = 1;		// B의 배수
	int A_multiple = 2;		// A에 곱할 값
	int B_multiple = 2;		// B에 곱할 값

	for (int i = 0; i < T; i++) {
		cin >> A >> B;

		A_result = A;
		B_result = B;
		A_multiple = 2;
		B_multiple = 2;

		// 최소공배수를 찾을 때까지 반복
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