#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> D(N + 1);
	D[1] = 1;
	D[2] = 1;		// 사람이 1명일 경우, 경우의 수는 본인이 하나도 받지 못 하는 경우 1개이다.

	for (int i = 2; i <= N; i++) {
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
	}

	D;

	return 0;
}