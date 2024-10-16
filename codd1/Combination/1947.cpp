#include <iostream>
#include <vector>

#define REMAINDER 1'000'000'000

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> D(N + 1);
	D[1] = 0;		// 사람이 1명일 경우, 경우의 수는 본인이 하나도 받지 못 하는 경우 1개이다.
	
	if (N >= 2) {		// D의 크기가 N + 1이기 때문에 메모리 초과를 방지하기 위한 처리
		D[2] = 1;		// 사람이 2명일 경우, 경우의 수는 서로 선물을 교환하는 경우 1개이다.
	}

	for (int i = 3; i <= N; i++) {
		D[i] = (i - 1) * ((D[i - 1] % REMAINDER) + (D[i - 2] % REMAINDER) % REMAINDER);		// 점화식
	}

	cout << D[N] % REMAINDER;

	return 0;
}