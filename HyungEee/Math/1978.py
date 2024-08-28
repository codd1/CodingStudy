import sys

n=int(sys.stdin.readline())
input=list(map(int,sys.stdin.readline().split()))
maxNum=max(input)

nums=[True]*(maxNum+1)
nums[0],nums[1]=False,False
count=0

for i in range(maxNum+1):
    if nums[i]==True:
        j=2
        while i*j<=maxNum:
           nums[i*j]=False 
           j+=1

for i in range(n):
    if nums[input[i]]:
        count+=1
print(count)
    
