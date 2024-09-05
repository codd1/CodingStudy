import sys

def gcd(a,b): # 최대공약수. 유틀리드 호제법을 사용
    if a<b:
        tmp=a
        a=b
        b=tmp
    while b!=0:
        r=a%b
        a=b
        b=r
    return a

n,s=map(int,sys.stdin.readline().split())
a=list(map(int,sys.stdin.readline().split()))
d=abs(s-a[0])
for i in range(1,n):
    d=gcd(d,abs(s-a[i]))
print(d)

# 풀이는 https://khyunx.tistory.com/11 참고하였음
# 수빈이는 좌우로 D칸씩 이동할 수 있고 모든 동생을 찾기 위한 D의 최댓값을 찾는 문제다.
# 즉, 모든 수빈이와 동생 사이의 거리의 최대공약수를 구하는 문제다.
# 먼저 첫 번째 동생과의 거리를 D라 하자.
# 다음 동생의 위치를 입력받을 때마다 입력받은 동생과의 거리와 D의 최대공약수를 D에 저장한다.
