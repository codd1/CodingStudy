import sys

n=int(sys.stdin.readline())
fac=1
count=0

if n>1:
    for i in range(n,1,-1):
        fac*=i
s=str(fac)

for i in reversed(s):
    if i!="0":
        break
    count+=1
print(count)
