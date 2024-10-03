import sys

t=int(sys.stdin.readline())
for _ in range(t):
    sticker=[]
    n=int(sys.stdin.readline())
    sticker.append(list(map(int,sys.stdin.readline().split())))
    sticker.append(list(map(int,sys.stdin.readline().split())))
    dp=[[0]*n for _ in range(2)]
    # dp[n][i]: n행 i열 까지의 최댓값
    if n==1:
        print(max(sticker[0][0],sticker[1][0]))
    elif n==2:
        print(max(sticker[1][0]+sticker[0][1],sticker[0][0]+sticker[1][1]))
    else:    
        dp[0][0],dp[1][0]=sticker[0][0],sticker[1][0]
        dp[0][1]=sticker[1][0]+sticker[0][1]
        dp[1][1]=sticker[0][0]+sticker[1][1]
        for i in range(2,n):
            dp[0][i]=max(dp[0][i-2],dp[1][i-2],dp[1][i-1])+sticker[0][i]
            dp[1][i]=max(dp[0][i-2],dp[1][i-2],dp[0][i-1])+sticker[1][i]
        print(max(dp[0][n-1],dp[1][n-1]))
