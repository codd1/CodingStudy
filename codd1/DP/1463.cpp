#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> DP(N + 1, INT_MAX);

	DP[1] = 0;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;		// (연산 3번) 1을 뺀다.

		if (i % 3 == 0) {			// (연산 1번) X가 3으로 나누어 떨어지면, 3으로 나눈다.
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
		
		if (i % 2 == 0) {			// (연산 2번) X가 2로 나누어 떨어지면, 2로 나눈다.
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
	}

	cout << DP[N];

	return 0;
}