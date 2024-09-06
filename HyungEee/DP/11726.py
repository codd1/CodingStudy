import sys

# 풀이 및 그림 참고 https://lecor.tistory.com/58

n=int(sys.stdin.readline())
dp=[0]*(n+1)
dp[0],dp[1]=1,1
# dp[n]=dp[n-1]+dp[n-2] 
# n-1번째 패턴에 세로 타일 한개 추가하기 + n-2번째 패턴에 가로타일 두개 추가하기

for i in range(2,n+1):
    dp[i]=dp[i-1]+dp[i-2]
    
print(dp[n]%10007)
