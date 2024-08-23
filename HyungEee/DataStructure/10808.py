import sys

s=list(sys.stdin.readline().rstrip())
alp=[0]*26

for i in s:
    alp[ord(i)-97]+=1

print(*alp, sep=" ")
