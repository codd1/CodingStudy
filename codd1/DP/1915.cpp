#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];		// dp[i][j]�� ��, i, j�� ��ġ�� ������ �Ʒ� ���������� ���ϰ�, �ش� �ڸ����� �׸� �� �ִ� ���� ū ���簢�� "��"�� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;		// n*m ũ���� �迭
	cin >> n >> m;

	char c;			// ���� ���� �Է��� �ֱ� ������ char ���� ����
	int max = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			dp[i][j] = c - '0';		// char�� �޾Ƽ� int�������� ��ȯ
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == 1) {		// �迭�� ���� 1�� ���,
				// �밢��, ����, ���� �� ���� ���� ���� 1�� ���Ѵ�.
				// ��, �밢��, ����, ���� ���� ��� ���ƾ� ������ ������ Ŀ���� �� �� �ִ�. (���� 1,1,1�̰� ���� ��ġ�� 1�̶�� �� ū ���簢�� 2�� ��)
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;

				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
		}
	}

	cout << max * max;

	return 0;
}