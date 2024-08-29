import sys

nums=[True]*1000001
nums[0],nums[1]=False,False

for i in range (2,1001):
    if nums[i]:
        for j in range (i*i,1000001,i):
           nums[j]=False

while True:
    n=int(sys.stdin.readline())
    if n==0:
        break
    if n%2!=0:
        print("Goldbach's conjecture is wrong.")
        continue
    for i in range(2,n):
        if nums[i] and nums[n-i]:
            print(f'{n} = {i} + {n-i}')
            break
