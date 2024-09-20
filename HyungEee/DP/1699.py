import sys
import math

# 해설 참고: https://daegwonkim.tistory.com/82

n=int(sys.stdin.readline())
dp=[i for i in range(100001)]

for i in range(n+1):
    for j in range(int(math.sqrt(i))+1):
        dp[i]=min(dp[i],dp[i-j*j]+1)
        # 점화식: dp[m] = min(dp[m], dp[m - 제곱수] + 1) 
print(dp[n])
