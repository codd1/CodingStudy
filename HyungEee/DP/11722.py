import sys

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
dp=[1]*n # dp[i]는 i번째 수를 포함하는 가장 긴 감소하는 부분수열의 길이
for i in range(1,n):
    tmp=0
    for j in range(i-1,-1,-1):
        # i번째 수보다 큰 수의 dp값 중 가장 큰 값을 더해줄 것임
        if a[i]<a[j] and dp[j]>tmp:
            tmp=dp[j]
    dp[i]+=tmp
print(max(dp))
