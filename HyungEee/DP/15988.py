import sys

MAX_NUM=1000001
t=int(sys.stdin.readline())
dp=[0]*MAX_NUM
dp[1],dp[2],dp[3]=1,2,4
for i in range(4,MAX_NUM):
    dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000009
    # dp[n-1]에 1을 더하는 경우, dp[n-2]에 2를 더하는 경우, dp[n-3]에 3을 더하는 경우

for _ in range(t):
    n=int(sys.stdin.readline())
    print(dp[n])
    
