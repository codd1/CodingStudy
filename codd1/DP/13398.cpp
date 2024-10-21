#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ContinuousSum(vector<vector<int>> dp) {		// 연속적인 합 중에 가장 큰 합 리턴
	int max = 0;

	for (int i = 0; i < dp.size(); i++) {
		for (int j = i + 1; j < dp.size(); j++) {
			dp[i][j] = dp[i][j - 1] + dp[j][j];
		}
	}

	for (int i = 0; i < dp.size(); i++) {
		if (max < *max_element(dp[i].begin(), dp[i].end())) {
			max = *max_element(dp[i].begin(), dp[i].end());
		}
	}

	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;		// n개의 정수로 이루어진 임의의 수열이 주어진다.
	cin >> n;
	
	vector<vector<int>> dp(n, vector<int>(n));
	vector<int> minus_input;
	int max = 0;

	for (int i = 0; i < n; i++) {
		cin >> dp[i][i];

		if (dp[i][i] < 0) {
			minus_input.push_back(i);	// 음수 인덱스(위치)를 저장
		}
	}

	max = ContinuousSum(dp);

	vector<vector<int>> copy_dp(n - 1, vector<int>(n - 1));		// dp의 복사본
	
	int func_result = 0;
	for (int i = 0; i < minus_input.size(); i++) {
		// 음수 1개씩 삭제해서 max 값 찾기 (erase 사용 시, copy[i][i] = dp[i][i+1]이 저장되는 문제 때문에 사용 X)
		for (int j = 0; j < n - 1; j++) {
			if (j >= minus_input[i]) {
				copy_dp[j][j] = dp[j + 1][j + 1];
			}
			else {
				copy_dp[j] = dp[j];
			}
		}

		func_result = ContinuousSum(copy_dp);
		if (max < func_result) {
			max = func_result;
		}

		copy_dp.resize(n - 1, vector<int>(n - 1));
	}

	cout << max;

	return 0;
}