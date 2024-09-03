#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long n;		// 자연수 n (입력값)
	cin >> n;

	long result = n;		// 서로소의 갯수

	for (long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {		// i가 소인수인지 확인 후 맞다면,
			result = result - result / i;	// result 값 업데이트 (오일러 피)

			while (n % i == 0) {	// n에 대한 소인수 지우기
				n /= i;
			}
		}
	}

	if (n > 1) {	// 만약 소인수가 남아있다면,
		result = result - result / n;	// 마지막 계산도 해야 함.
	}

	cout << result << endl;

	return 0;
}