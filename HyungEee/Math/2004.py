import sys

n,m=map(int,sys.stdin.readline().split())

# 팩토리얼로 풀면 시간이 초과되므로 조합식에서 10의 지수를 구하는 방식으로 풀어줘야 한다.
def solution(n,k): # N!에서 k의 지수 개수를 구하는 방법은 k^i로 N을 계속 나눠주면 된다.
    cnt=0
    while n>1:
        n//=k
        cnt+=n
    return cnt

five=solution(n,5)-solution(m,5)-solution(n-m,5) # 조합에서 5의 지수 개수
two=solution(n,2)-solution(m,2)-solution(n-m,2) # 조합에서 2의 지수 개수
print(min(five, two)) # 둘 중 작은 것이 10의 지수 개수(끝자리 0의개수)임
