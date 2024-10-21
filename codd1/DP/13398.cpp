#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ContinuousSum(vector<vector<int>> dp) {		// �������� �� �߿� ���� ū �� ����
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

	int n;		// n���� ������ �̷���� ������ ������ �־�����.
	cin >> n;
	
	vector<vector<int>> dp(n, vector<int>(n));
	vector<int> minus_input;
	int max = 0;

	for (int i = 0; i < n; i++) {
		cin >> dp[i][i];

		if (dp[i][i] < 0) {
			minus_input.push_back(i);	// ���� �ε���(��ġ)�� ����
		}
	}

	max = ContinuousSum(dp);

	vector<vector<int>> copy_dp(n - 1, vector<int>(n - 1));		// dp�� ���纻
	
	int func_result = 0;
	for (int i = 0; i < minus_input.size(); i++) {
		// ���� 1���� �����ؼ� max �� ã�� (erase ��� ��, copy[i][i] = dp[i][i+1]�� ����Ǵ� ���� ������ ��� X)
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