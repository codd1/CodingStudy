import sys

n=int(sys.stdin.readline())
laser=list(map(int,sys.stdin.readline().split()))
stack=[]

for i in range(n):
    h=laser[i] # 스택에 추가하려는 탑의 높이
    while(stack): 
        if stack[-1][1]>h: # 추가하려는 요소보다 큰 값이 나오면 수신할 수 있으므로 print
            print(stack[-1][0],end=" ")
            break
        stack.pop() # 아니라면 추가하려는 요소보다 큰 값이 나올 때까지 pop 
    if not stack:
        print(0,end=" ") # 스택에 값이 없다면 0을 print
    stack.append([i+1,laser[i]]) # 새로운 요소를 [인덱스, 높이] 형식으로 append. 

# index함수는 배열을 처음부터 하나하나 탐색해서 찾는 함수라 시간이 오래걸림.
# 인덱스 함수를 쓰지말고 인덱스 값을 저장해서 쓰도록 하자!!!!!
