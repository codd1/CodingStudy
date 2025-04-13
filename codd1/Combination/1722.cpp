#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// N개의 수
	cin >> N;

	vector<long> vecN(N + 1);
	vector<long> factorial(N + 1, 1);

	int type;

	cin >> type;

	for (int i = 1; i <= N; i++) {
		vecN[i] = i;		// 1, 2, 3, ..., N

		factorial[i] = factorial[i - 1] * i;
	}

	long K;

	if (type == 1) {	// K번째 순열 출력
		cin >> K;

		long count = 1;

		for (int i = 0; i < N; i++) {
			while (K > factorial[N - i - 1] * count) {	// K와 현재 자리 - 1에서 만들 수 있는 경우의 수를 비교
				count++;								// K가 더 작아질 때까지 count++
			}

			cout << vecN[count] << " ";

			K = K - (factorial[N - i - 1] * (count - 1));		// K 값 업데이트

			vecN.erase(vecN.begin() + count);		// 순열에서 출력한 값 제거
			count = 1;
		}
	}
	else if (type == 2) {	// 주어진 순열이 몇 번째 순열인지 출력
		vector<int> input(N);
		K = 1;		// K의 기본값 = 1

		for (int i = 0; i < N; i++) {
			cin >> input[i];

			long count = 1;

			if (vecN[count] != input[i]) {			// 현재 자릿수의 숫자를 확인하고
				while (vecN[count] < input[i]) {	// 해당 숫자보다 앞 숫자 중 미사용된 숫자 갯수를 카운트
					count++;
				}

				K = K + factorial[N - i - 1] * (count - 1);		// K 값 업데이트
			}

			vecN.erase(vecN.begin() + count);		// 순열에서 출력한 값 제거
		}

		cout << K;
	}

	return 0;
}