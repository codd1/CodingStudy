import sys
import copy

n=int(sys.stdin.readline())
tri=[0]*n
for i in range(n):
    tri[i]=list(map(int,sys.stdin.readline().split()))
dp=copy.deepcopy(tri) # 삼각형의 꼭대기에서 한줄씩 차례로 dp를 구해갈 것임

for i in range(1,n):
    for j in range(i+1):
        if j==0:
            dp[i][j]+=dp[i-1][0] # i번째 줄의 첫번째 정수는 i-1줄의 첫번째 정수만 선택 가능
        elif j==i:
            dp[i][j]+=dp[i-1][j-1] # i번째 줄의 마지막 정수는 i-1줄의 마지막 정수만 선택 가능
        else:
            dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]) # i번째 줄의 j번째 정수는 i-1줄의 j-1번째와 j번째 중 큰 것을 선택
print(max(dp[n-1]))
