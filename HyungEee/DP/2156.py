import sys

n=int(sys.stdin.readline())
glass=[0]
for _ in range(n):
    glass.append(int(sys.stdin.readline()))
    
if n==1:
    print(glass[1])
elif n==2:
    print(glass[1]+glass[2])
else:
    dp=[0]*(n+1)
    dp[1]=glass[1]
    dp[2]=dp[1]+glass[2]
    for i in range(3,n+1):
        
        dp[i]=max(dp[i-1],dp[i-3]+glass[i-1]+glass[i],dp[i-2]+glass[i]) 
        # 1) i번째 잔을 선택하지 않는 경우 => dp[i-1]과 같음
        #   (두 잔을 연속으로 선택하지 않는 경우도 있으므로 이 경우는 꼭 넣어주어야 함)
        # 2) i번째 잔과 i-1번째 잔을 선택하는 경우 => dp[i-3]와 glass[i-1]의 값을 더해줌
        # 3) i번째 잔을 선택하고, i-1번째 잔을 선택하지 않는 경우 =>dp[i-2] 값을 더해줌
        # 셋 중 최댓값이다.
    print(dp[n])
