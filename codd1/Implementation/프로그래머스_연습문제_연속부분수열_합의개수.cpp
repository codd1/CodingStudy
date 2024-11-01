#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

    int dp[1001][1001] = { 0, };
    set<int> s;

    for (int i = 0; i < elements.size(); i++) {
        dp[i][i] = elements[i];     // i ~ i의 부분 수열의 값은 i
        s.insert(dp[i][i]);
    }

    for (int i = 0; i < elements.size(); i++) {
        for (int j = i; j < elements.size(); j++) {
            if (dp[i][j] == 0) {
                if (j == 0) {
                    dp[i][j] = dp[i][i] + dp[0][i - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1] + dp[j][j];
                }
                s.insert(dp[i][j]);
            }
        }
    }

    for (int i = elements.size() - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (dp[i][j] == 0) {
                dp[i][j] = dp[i][elements.size() - 1] + dp[0][j];

                s.insert(dp[i][j]);
            }
        }
    }

    answer = s.size();

    return answer;
}