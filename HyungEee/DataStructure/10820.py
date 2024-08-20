import sys

while True:
    str=list(sys.stdin.readline().strip('\n'))
    low,upp,num,blank=0,0,0,0
    if not str:
        break
    for i in str:
        if i>='A' and i<='Z':
            upp+=1
        elif i>='a' and i<='z':
            low+=1
        elif i==" ":
            blank+=1
        else:
            num+=1
    print(low, upp, num, blank)
