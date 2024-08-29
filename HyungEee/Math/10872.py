import sys

n=int(sys.stdin.readline())
ans=1

if n==0 or n==1:
    print(1)
else:
    for i in range(n,1,-1):
        ans*=i
    print(ans)
