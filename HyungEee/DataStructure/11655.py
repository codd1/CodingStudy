import sys

s=list(sys.stdin.readline().rstrip())
str=''
for i in s:
    if i>='A' and i<='Z':
        n=ord(i)+13
        if n>90:
            n-=26
        str+=chr(n)
    elif i>='a' and i<='z':
        n=ord(i)+13
        if n>122:
            n-=26
        str+=chr(n)
    else:
        str+=i
print(*str, sep="")
