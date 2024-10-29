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
			// 두 문자가 같을 경우, 대각선 왼쪽 위 값 + 1 (설명을 위해 같은 문자를 char로 칭한다)
			// = char가 없었을 때의 LCS 길이(대각선 왼쪽 위 값)에 동시에 새로 char가 추가되므로 + 1
			if (str1[i - 1] == str2[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}

	cout << DP[str1.size()][str2.size()] << "\n";		// 두 문자열의 LCS 길이 출력

	for (int i = str1.size(), j = str2.size(); i >= 1 && j >= 1;) {
		if (str1[i - 1] == str2[j - 1]) {
			output.push_back(str1[i - 1]);		// LCS를 역으로 탐색하므로 벡터에 저장해뒀다가 나중에 역순으로 출력하는 작업 필요

			i = i - 1;			// 대각선 왼쪽 위로 이동한다
			j = j - 1;
		}
		else {
			if (DP[i][j] == DP[i - 1][j]) {			// 위쪽 값과 같은지?
				i = i - 1;		// 위쪽으로 이동한다
			}
			else if (DP[i][j] == DP[i][j - 1]) {	// 왼쪽 값과 같은지?
				j = j - 1;		// 왼쪽으로 이동한다
			}
		}
	}

	for (int i = output.size() - 1; i >= 0; i--) {
		cout << output[i];
	}

	return 0;
}