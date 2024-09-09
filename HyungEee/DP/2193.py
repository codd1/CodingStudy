import sys

dp=[[0]*2 for _ in range(91)]
dp[1][1],dp[2][0]=1,1
for i in range(3,91):
    dp[i][0]=dp[i-1][0]+dp[i-1][1]
    dp[i][1]=dp[i-1][0]
# 배열의 1차원은 n을, 2차원은 끝자리가 0인지 1인지를 나타냄
# n자리 이친수의 개수: dp[n][0]+dp[n][1]
# dp[n][0]=dp[n-1][0]+dp[n-1][1] (n-1번째 경우의 모든 숫자 뒤에 0 추가하기) 
# dp[n][1]=dp[n-1][0] (n-1번째 경우의 끝자리가 0인 숫자들 뒤에 1추가하기)

n=int(sys.stdin.readline())
print(dp[n][0]+dp[n][1])
