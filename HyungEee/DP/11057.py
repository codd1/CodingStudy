import sys

n=int(sys.stdin.readline())
if n==1:
    print(10)
else:
    dp=[[1]*10 for _ in range(n+1)] 
    #행:0~n, 열: 해당 열 인덱스로 끝나는 수의 갯수
    for i in range(2,n+1):
        for j in range(1,10):
            dp[i][j]=dp[i][j-1]+dp[i-1][j]
    print(sum(dp[n])%10007)
