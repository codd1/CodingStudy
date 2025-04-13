#include <iostream>
#include <vector>
#include <string>
#include <cmath>	// pow()

using namespace std;

int main() {
	int N;		// N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서 가장 작은 수 구하기

	cin >> N;	// (1 ≤ N ≤ 1,000,000)

	vector<int> prime(1004000, 1);	// 정답의 최댓값이 1003001이기 때문에 범위를 1004000으로 잡음.
	prime[0] = 0;
	prime[1] = 0;

	// 소수만 남게 하기
	int multiple = 2;
	for (int i = 2; i < prime.size(); i++) {
		multiple = 2;
		while (i * multiple < prime.size()) {
			prime[i * multiple] = 0;
			multiple++;
		}
	}

	bool isPalindrome = true;	// 소수이면서 팰린드롬 수인지?
	string num;

	for (int i = 2; i < prime.size(); i++) {
		if (prime[i] == 1) {	// 소수인 것 중에
			num = to_string(i);
			isPalindrome = true;

			for (int j = 0; j < num.size() / 2; j++) {		// 팰린드롬 수인지 확인
				if (num[j] == num[num.size() - (j + 1)]) {
					continue;
				}
				prime[i] = 0;
				isPalindrome = false;
				break;
			}

			if (isPalindrome && i >= N) {	// 소수이면서 팰린드롬 수이고 N 이상이라면 출력 후 종료
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}