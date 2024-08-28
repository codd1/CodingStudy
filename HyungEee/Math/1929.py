import sys

m,n=map(int,sys.stdin.readline().split())

nums=[True]*1000001
nums[0],nums[1]=False,False

for i in range(n+1):
    if nums[i]==True:
        j=2
        while i*j<=n:
           nums[i*j]=False 
           j+=1

for i in range(m,n+1):
    if nums[i]:
        print(i)
