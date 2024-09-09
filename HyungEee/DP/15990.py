import sys

MOD=1000000009

dp=[[0]*4 for _ in range(100001)]
# 파이썬에서 2차원 리스트를 초기화 할 때는 반드시 컴프리헨션을 사용해야함!!
# 컴프리헨션을 사용하지 않고 [[0]*4]*100001 이렇게 하면 오류 발생함!!

dp[1][1],dp[2][2],dp[3][1],dp[3][2],dp[3][3]=1,1,1,1,1
for i in range(4,100001):
    dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MOD
    dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MOD
    dp[i][3]=(dp[i-3][1]+dp[i-3][2])%MOD
# 배열의 1차원은 n을, 2차원은 1,2,3으로 끝나는 갯수를 나타냄
# dp[n][0]=dp[n-1]에서 2,3으로 끝나는거 (dp[n-1][2]+dp[n-1][3])
# dp[n][0]=dp[n-2]에서 1,3으로 끝나는거 (dp[n-2][1]+dp[n-2][3])
# dp[n][0]=dp[n-3]에서 1,2로 끝나는거 (dp[n-3][1]+dp[n-3][2])
# answer=dp[n][0]+dp[n][1]+dp[n][2]

t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    print(sum(dp[n])%MOD)
