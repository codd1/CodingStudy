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
		DP[i] = DP[i - 1] + 1;		// (���� 3��) 1�� ����.

		if (i % 3 == 0) {			// (���� 1��) X�� 3���� ������ ��������, 3���� ������.
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
		
		if (i % 2 == 0) {			// (���� 2��) X�� 2�� ������ ��������, 2�� ������.
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
	}

	cout << DP[N];

	return 0;
}