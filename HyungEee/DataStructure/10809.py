import sys

s=list(sys.stdin.readline().rstrip())
alp=[-1]*26

for i in range(len(s)):
    n=ord(s[i])-97
    if alp[n]==-1:
        alp[n]=i
        
print(*alp, sep=" ")
