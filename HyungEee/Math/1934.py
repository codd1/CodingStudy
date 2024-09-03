import sys

#유클리드 호제법:
#2개의 자연수 a, b(a > b)에 대해서 a를 b로 나눈 나머지가 r일 때, a와 b의 최대공약수는 b와 r의 최대공약수와 같다. 
def gcd(a,b):
    if a<b:
        tmp=a
        a=b
        b=tmp
    while b!=0:
        r=a%b
        a=b
        b=r
    return a

t=int(sys.stdin.readline())
for i in range(t):
    a,b=map(int,sys.stdin.readline().split())
    lcm=a*b//gcd(a,b) #최소공배수는 두 수의 곱을 최대공약수로 나눈 것과 같다
    print(lcm)
