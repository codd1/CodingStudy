import sys

n=int(sys.stdin.readline())
seq=list(map(int,sys.stdin.readline().split()))

dp=[0]*n # dp[i]는 seq[i]까지 고려했을때(이때 seq[i]는 연속합에 무조건 포함됨)의 연속합의 최댓값이다.
dp[0]=seq[0]
for i in range(1,n):
    dp[i]=max(dp[i-1]+seq[i],seq[i])
    
print(max(dp))
