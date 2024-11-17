#include <string>
#include <vector>

#define MOD 1234567

using namespace std;

long long solution(int n) {
    long long answer = 0;

    int dp[2001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }

    answer = dp[n] % MOD;

    return answer;
}