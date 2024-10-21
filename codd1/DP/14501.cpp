#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> input(N + 1);		// 상담일정
	vector<int> DP(N + 1, 0);		// 결과

	int T, P;	// T: 상담 시간(일), P: 상담 비용
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;

		input[i] = make_pair(T, P);
	}

	for (int i = 1; i <= N; i++) {
		if (input[i].first == 1) {		// T == 1
			DP[i] = max(DP[i], DP[i - 1] + input[i].second);	// 상담 시간이 1일인 경우, max(DP[N], 전날 최댓 값(DP[N-1])에 오늘의 상담 페이를 더한 값)
		}
		else {
			DP[i] = max(DP[i], DP[i - 1]);

			if (i + input[i].first <= N + 1) {		// 메모리 초과 방지
				// N + T - 1 = 오늘 날짜에 오늘 상담 시간만큼 더한 값
				// DP[N + T - 1] = max(DP[N + T - 1], 오늘의 상담 페이 + 전날까지의 상담 페이 최댓값)
				DP[i + input[i].first - 1] = max(DP[i + input[i].first - 1], input[i].second + DP[i - 1]);
			}
		}
	}

	cout << DP[N];

	return 0;
}