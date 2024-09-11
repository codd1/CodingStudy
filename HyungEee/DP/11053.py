import sys

# 풀이 참고: https://great-park.tistory.com/28

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
dp=[1]*n #가장 긴 수열의 길이를 저장하는 리스트, 길이에는 자신이 포함되므로 1로 초기화함

for i in range(n):
    for j in range(i): 
        if a[j]<a[i]:
            dp[i]=max(dp[i],dp[j]+1) #dp에는 해당 인덱스를 끝으로 하는 부분수열의 최대 길이가 담기게 됨.

print(max(dp))
