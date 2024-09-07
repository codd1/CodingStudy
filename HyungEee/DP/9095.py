import sys

t=int(sys.stdin.readline())
dp=[0]*11
dp[1],dp[2],dp[3]=1,2,4
# dp[n]=dp[n-1]+dp[n-2]+dp[n-3]
# n-1에 1을 더하기, n-2에 2를 더하기, n-3에 3을 더하기

for i in range(4,11):
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3]

for i in range(t):
    print(dp[int(sys.stdin.readline())])
