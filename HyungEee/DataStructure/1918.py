import sys 

infix=list(sys.stdin.readline().rstrip())
postfix=list()
stack=list()

for i in infix:
    if i>='A' and i<='Z':
        postfix.append(i) #알파벳은 바로 정답에 등록
    elif i=='(':
        stack.append(i) #괄호 안의 연산은 스택에 저장한다
    elif i=='*' or i=='/': 
        while stack and (stack[-1]=='*' or stack[-1]=='/'): #곱셈, 나눗셈 연산만 pop하여 정답에 등록(곱,나눗셈은 우선순위가 덧뺄셈보다 높아 먼저 계산되어야 하므로)
            postfix.append(stack.pop())
        stack.append(i) #스택에 연산자 등록
    elif i=='+' or i=='-': 
        while stack and stack[-1]!='(': #( 전까지의 연산을 모두 pop하여 정답에 등록
            postfix.append(stack.pop())
        stack.append(i) #스택에 연산자 등록
    elif i==')':
        while stack and stack[-1]!='(':
            postfix.append(stack.pop()) #여는 괄호 전까지 pop하여 정답에 등록
        stack.pop() #여는 괄호 제거
while stack:
    postfix.append(stack.pop()) #남아있는 연산자들 모두 정답에 등록
    
print(*postfix,sep="")
