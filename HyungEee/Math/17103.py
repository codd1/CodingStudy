import sys

nums=[True]*1000001
nums[0],nums[1]=False,False

for i in range (2,1001):
    if nums[i]:
        for j in range (i*i,1000001,i):
           nums[j]=False
           
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    count=0
    for i in range(2,n//2+1):
        if nums[i] and nums[n-i]:
            count+=1
    print(count)
