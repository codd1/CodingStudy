import sys

n=int(sys.stdin.readline())
li=[]
if n==0:
    print(0)
else:
    while n!=0:
        i=n%(-2)
        if i>=0:
            li.append(i)
            n//=-2
        else:
            li.append(1)
            n=n//-2+1
    print(*li[::-1],sep="")
