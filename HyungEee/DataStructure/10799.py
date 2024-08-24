import sys

input=list(sys.stdin.readline())
stack=list()
piece=0
for i in range(len(input)-1):
    if input[i]=="(":
        stack.append("(")
    else:
        stack.pop()
        if input[i-1]=="(": #레이저
            piece+=len(stack)
        else: #막대기
            piece+=1
print(piece)
