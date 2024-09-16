import sys

# 풀이 참고: https://kkkdh.tistory.com/entry/BOJ-14002%EB%B2%88-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-4-%EB%AC%B8%EC%A0%9C-LIS-%EC%98%88%EC%A0%9C%EC%99%80-DP-%ED%92%80%EC%9D%B4

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split())) # 전체 수열을 저장.

# 1차원 배열을 이용해서 가장 긴 증가하는 부분 수열을 찾았다면, 
# 한 차원을 더 추가해서 가장 긴 길이를 갱신할때 사용한 이전 원소의 위치(index)를 기록하면 됨.
dp=[[0]*2 for _ in range(n)] # 열 필드에서 [0]:수열의 길이 [1]:이전 원소의 index
for i in range(n): # 길이와 이전 index를 초기화
    dp[i][0]=1
    dp[i][1]=i

for i in range(n):
    currValue=a[i]
    currIdx=i
    for j in range(i): 
        prevValue=a[j]
        prevIdx=j
        if currValue>prevValue:
            # 최대 길이를 갱신할 수 없는 경우
            if dp[currIdx][0]>dp[prevIdx][0]+1:
                continue
            else: #최대 길이를 갱신할 수 있는 경우, 길이와 이전 index를 갱신한다.
                dp[currIdx][0]=dp[prevIdx][0]+1
                dp[currIdx][1]=j
    
maxLen=0
maxIdx=0
for i in range(n):
    if maxLen<dp[i][0]:
        maxLen=dp[i][0]
        maxIdx=i
        
res=list()
while(True):
    res.append(a[maxIdx]) #부분 수열의 이전 원소로 이동하면서 하나씩 res에 넣는다.
    if maxIdx==dp[maxIdx][1]: #자신이 수열의 마지막인 경우 종료
        break
    maxIdx=dp[maxIdx][1]
    
print(maxLen)
for i in range(len(res)-1,-1,-1):
    print(res[i],end=" ")
