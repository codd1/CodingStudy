import sys 

n=int(sys.stdin.readline())
nums=list(map(int,sys.stdin.readline().split()))
appear=[0]*10000001 #등장횟수
ngf=[-1]*n #오등큰수
stack=list() #nums의 인덱스를 저장하는 스택

for i in nums:
    appear[i]+=1 #등장횟수를 카운트

for i in range(n):
    while stack and appear[nums[stack[-1]]]<appear[nums[i]]: #nums[top]의 등장횟수가 nums[i]의 등장횟수보다 작으면 nums[top]의 오등큰수는 nums[i]이다.
        ngf[stack.pop()]=nums[i]
    stack.append(i) #스택에 해당 인덱스를 추가.
    
print(*ngf,sep=" ")
