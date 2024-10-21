#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;		// n개의 정수로 이루어진 임의의 수열이 주어진다.
	cin >> n;
	
	vector<int> dp(n);
	vector<int> left(n);
	vector<int> right(n);

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}

	left[0] = dp[0];
	right[n - 1] = dp[n - 1];

	for (int i = 1; i < n; i++) {
		left[i] = max(dp[i], left[i - 1] + dp[i]);		// 왼쪽에서부터 i을 포함한 최대 연속 합
	}

	for (int j = n - 2; j >= 0; j--) {
		right[j] = max(dp[j], right[j + 1] + dp[j]);	// 오른쪽에서부터 j을 포함한 최대 연속 합
	}
	
	int max = *max_element(left.begin(), left.end());	// 수를 1개 제거하지 않는 경우

	// 수열에서 수를 1개 제거하는 경우
	for (int i = 1; i < n - 1; i++) {
		if (left[i - 1] + right[i + 1] > max) {
			max = left[i - 1] + right[i + 1];
		}
	}

	cout << max;

	return 0;
}