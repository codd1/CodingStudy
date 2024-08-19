#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;		// 동전의 종류 갯수
	int K;		// 만들려는 가치의 합
	int count = 0;		// K원을 만드는 데 필요한 동전 개수의 최솟값 = 정답

	cin >> N >> K;

	vector<int> coin(N);

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	// 가장 가격이 큰 동전부터 차례대로 사용한다.
	for (int i = N - 1; i >= 0; i--) {
		if (coin[i] <= K) {
			while (K >= coin[i]) {
				K -= coin[i];
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}