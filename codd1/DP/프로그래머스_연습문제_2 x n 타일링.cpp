#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;

    int dp[60001];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }

    answer = dp[n] % MOD;

    return answer;
}