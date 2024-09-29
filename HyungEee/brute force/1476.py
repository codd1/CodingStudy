import sys

e,s,m=map(int,sys.stdin.readline().split())

year=1
while e!=1 or s!=1 or m!=1:
    e-=1
    s-=1
    m-=1
    year+=1
    if e==0:
        e=15
    if s==0:
        s=28
    if m==0:
        m=19
print(year)
