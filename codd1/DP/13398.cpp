#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;		// n���� ������ �̷���� ������ ������ �־�����.
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
		left[i] = max(dp[i], left[i - 1] + dp[i]);		// ���ʿ������� i�� ������ �ִ� ���� ��
	}

	for (int j = n - 2; j >= 0; j--) {
		right[j] = max(dp[j], right[j + 1] + dp[j]);	// �����ʿ������� j�� ������ �ִ� ���� ��
	}
	
	int max = *max_element(left.begin(), left.end());	// ���� 1�� �������� �ʴ� ���

	// �������� ���� 1�� �����ϴ� ���
	for (int i = 1; i < n - 1; i++) {
		if (left[i - 1] + right[i + 1] > max) {
			max = left[i - 1] + right[i + 1];
		}
	}

	cout << max;

	return 0;
}