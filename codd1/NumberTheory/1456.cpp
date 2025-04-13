#include <iostream>
#include <vector>
#include <cmath>	// sqrt, pow

using namespace std;

int main() {
	long long A, B;		// A보다 크거나 같고 B보다 작거나 같은 '거의 소수' 구하기
	int count = 0;	// '거의 소수' 갯수

	cin >> A >> B;

	long long square_root = sqrt(static_cast<long long>(B));	// B의 제곱근
	vector<int> almost_prime(square_root + 1, 1);				// 거의 소수
	almost_prime[0] = 0;
	almost_prime[1] = 0;

	int multiply = 2;		// i에 곱할 값
	int multiple = 0;		// i의 배수
	for (int i = 2; i <= square_root; i++) {	// 범위가 1~10^14로 크기 때문에 "제곱근"을 구해 계산
		if (almost_prime[i] == 1) {		// i가 소수 후보에 있는 값이라면
			multiple = i * multiply;
			while (multiple <= square_root) {	// i의 배수들은 모두 값을 0으로 만든다. (소수가 아니라는 뜻)
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
			while (pow(i, multiply) <= B) {		// 예를 들어, 10 20이 입력됐을 때 2^4가 '거의 소수'인데 A <= pow <= B로 조건을 둘 경우
												// 그냥 넘어가기 때문에 while문 조건과 아래 if문 조건을 따로 둔다.
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