#include <iostream>
#include <string>
#include <vector>

using namespace std;

int DP[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<char> output;

	string str1;
	string str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			// �� ���ڰ� ���� ���, �밢�� ���� �� �� + 1 (������ ���� ���� ���ڸ� char�� Ī�Ѵ�)
			// = char�� ������ ���� LCS ����(�밢�� ���� �� ��)�� ���ÿ� ���� char�� �߰��ǹǷ� + 1
			if (str1[i - 1] == str2[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}

	cout << DP[str1.size()][str2.size()] << "\n";		// �� ���ڿ��� LCS ���� ���

	for (int i = str1.size(), j = str2.size(); i >= 1 && j >= 1;) {
		if (str1[i - 1] == str2[j - 1]) {
			output.push_back(str1[i - 1]);		// LCS�� ������ Ž���ϹǷ� ���Ϳ� �����ص״ٰ� ���߿� �������� ����ϴ� �۾� �ʿ�

			i = i - 1;			// �밢�� ���� ���� �̵��Ѵ�
			j = j - 1;
		}
		else {
			if (DP[i][j] == DP[i - 1][j]) {			// ���� ���� ������?
				i = i - 1;		// �������� �̵��Ѵ�
			}
			else if (DP[i][j] == DP[i][j - 1]) {	// ���� ���� ������?
				j = j - 1;		// �������� �̵��Ѵ�
			}
		}
	}

	for (int i = output.size() - 1; i >= 0; i--) {
		cout << output[i];
	}

	return 0;
}