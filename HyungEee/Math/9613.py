import sys

def gcd(a,b): #유클리드 호제법
    if b==0:
        return a
    return gcd(b,a%b)

t=int(sys.stdin.readline())

for _ in range(t):
    nums=list(map(int,sys.stdin.readline().split()))
    n=len(nums)
    sum=0
    for i in range(1,n):
        for j in range(i+1,n):
            if nums[i]<nums[j]:
                sum+=gcd(nums[i],nums[j])
            else:
                sum+=gcd(nums[j],nums[i])
    print(sum)
