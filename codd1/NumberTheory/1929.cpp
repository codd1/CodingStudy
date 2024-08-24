#include <iostream>
#include <vector>

using namespace std;

int main() {
	int M;		// M 이상
	int N;		// N 이하의 소수 찾기

	cin >> M >> N;

	vector<int> prime(N + 1 , 1);	// 에라토스테네스 방법을 이용
	prime[0] = 0;
	prime[1] = 0;

	int multiply = 2;		// prime[i]에 곱할 값 (배수를 없애기 위함)
	int multiple = 0;		// prime[i]의 배수

	for (int i = 2; i <= N; i++) {
		if (prime[i] == 1) {	// 아직 지워진 수가 아니라면, (= 소수 후보에 있는 수라면)
			multiple = i * multiply;
			while (multiple <= N) {		// i의 배수들은 모두 0으로 표시
				prime[multiple] = 0;	// 0이라는 것은 소수가 아니라는 것
				multiple = i * multiply;
				multiply++;
			}
		}

		multiply = 2;
		multiple = 0;
	}

	for (int i = M; i <= N; i++) {
		if (prime[i] == 1) {	// 1이 남아있는 값 = 소수만 출력
			cout << i << endl;
		}
	}

	return 0;
}