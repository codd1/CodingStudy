import sys

s=sys.stdin.readline().rstrip()
suffix=list()

for i in range(len(s)):
    suffix.append(s[i:])
suffix.sort()

print(*suffix,sep="\n")
