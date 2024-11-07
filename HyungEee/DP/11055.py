import sys

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
dp=[0]*n # dp[i]는 i번째 수를 포함하는 가장 큰 증가하는 부분수열의 합
dp[0]=a[0]
for i in range(1,n):
    dp[i]+=a[i]
    tmp=0
    for j in range(i-1,-1,-1):
        # i번째 수보다 작은 수의 dp값 중 가장 큰 값을 더해줄 것임
        if a[i]>a[j] and dp[j]>tmp:
            tmp=dp[j]
    dp[i]+=tmp
print(max(dp)) #구한 dp중 가장 큰 값 출력
