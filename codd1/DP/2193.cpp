#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// N자리 수의 이친수
	cin >> N;

	vector<long long> DP(N + 1);

	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 2] + DP[i - 1];
	}

	cout << DP[N];

	return 0;
}