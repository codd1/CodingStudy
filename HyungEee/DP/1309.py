import sys

n=int(sys.stdin.readline())
dp=[0]*(n+1)
dp[0],dp[1]=1,3

for i in range(2,n+1):
    dp[i]=((dp[i-1]-dp[i-2])*2+dp[i-2]*3)%9901
    # dp[n]을 구할 때, dp[n-1]에서 
    # 맨 아랫줄이 비어있지 않은 경우는 왼 or 오, 빈칸의 2가지 추가 가능
    # 맨 아랫줄이 비어있는 경우는 왼,오,빈칸의 3가지 추가 가능 
    # 이때 dp[n-1]의 맨 아랫줄이 비어있는 경우의 수는 dp[n-2]와 같음
    
print(dp[n])
