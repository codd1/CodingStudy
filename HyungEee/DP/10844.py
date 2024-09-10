import sys

# 풀이 참고: https://data-make.tistory.com/412

MOD=1000000000

n=int(sys.stdin.readline())

dp=[[0]*11 for _ in range(n+1)] #행:수의 길이(n), 열:마지막숫자(0~9), 합계
for i in range(1,10):
    dp[1][i]=1
dp[1][10]=sum(dp[1])

for i in range(2,n+1):
    dp[i][0]=dp[i-1][1]
    for j in range(1,9):
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD
    dp[i][9]=dp[i-1][8]
    dp[i][10]=sum(dp[i])

print(dp[n][10]%MOD)
