import sys

n=int(sys.stdin.readline())
p=list(map(int,sys.stdin.readline().split()))
p.insert(0,0)

dp=[0]*(n+1)
dp[1]=p[1]
for i in range(2,n+1):
    dp[i]=p[i] # p[i] 1개만 구매하는 경우
    for j in range(i//2+1): # dp[i-j] + dp[j]의 조합으로 구매하는 경우
        dp[i]=min(dp[i],dp[i-j]+dp[j])
# dp[n] = min(p[n], dp[n-1]+dp[1], dp[n-2]+dp[2],...,dp[n-i]+dp[i])

print(dp[n])
