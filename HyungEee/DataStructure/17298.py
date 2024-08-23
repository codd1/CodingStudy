import sys

n=int(sys.stdin.readline())
seq=list(map(int,sys.stdin.readline().split()))
nge=[-1]*n #오큰수를 저장
stack=list() #seq의 인덱스를 저장

for i in range(n-1,-1,-1):
    while stack:
        if seq[i]<seq[stack[-1]]:
            nge[i]=seq[stack[-1]]
            break
        else:
            stack.pop()
    stack.append(i)

print(*nge,sep=" ")  
