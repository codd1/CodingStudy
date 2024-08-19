#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;		// 배열의 크기 N
	int k;		// 구할 B의 인덱스 값

	cin >> N >> k;

	int start = 1;
	int end = k;
	int median = (1 + k) / 2;		// 이진 탐색을 위한 중앙값

	int sum = 0;		// median보다 작거나 같은 수의 갯수


	while (start <= end) {
		median = (start + end) / 2;
		sum = 0;

		for (int i = 1; i <= N; i++) {
			sum += min(median / i, N);		// count는 median을 각 행의 첫 번째 값(1,2,3)으로 나눈 값의 총합이다. (예제에서는 1+2+3=6)
											// 하지만 한 행의 크기가 N이므로 N보다 클 경우 N 값으로 더한다.
		}

		if (k > sum) {		// 중앙값보다 작은 수의 갯수(sum)가 k보다 작으면,
			start = median + 1;
		}
		else {				// 중앙값보다 작은 수의 갯수가 k보다 크거나 같으면,
			end = median - 1;
		}
	}

	cout << start << endl;

	return 0;
}