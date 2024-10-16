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
	D[1] = 1;		// 사람이 1명일 경우, 경우의 수는 본인이 하나도 받지 못 하는 경우 1개이다.
	D[2] = 1;		// 사람이 2명일 경우, 경우의 수는 서로 선물을 교환하는 경우 1개이다.
	D[3] = 2;		// 사람이 3명일 경우, 경우의 수는 B A C / C A B 2개이다.

	for (int i = 4; i <= N; i++) {
		D[i] = (i - 1) * ((D[i - 1] % REMAINDER) + (D[i - 2] % REMAINDER) % REMAINDER);		// 점화식
	}

	cout << D[N] % REMAINDER;

	return 0;
}