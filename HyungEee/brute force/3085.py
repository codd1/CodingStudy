import sys

def swap(candy,i,j,k,l):
    tmp=candy[i][j]
    candy[i][j]=candy[k][l]
    candy[k][l]=tmp
    return candy

def maxCandy(candy,n):
    rowMax,colMax=1,1
    for i in range(n):
        rowCnt=1
        for j in range(n-1): #가로로 비교
            if candy[i][j]==candy[i][j+1]:
                rowCnt+=1
            else:
                rowCnt=1
            rowMax=max(rowMax,rowCnt)
    for i in range(n):
        colCnt=1
        for j in range(n-1): #세로로 비교
            if candy[j][i]==candy[j+1][i]:
                colCnt+=1
            else:
                colCnt=1
            colMax=max(colMax,colCnt)
    return max(rowMax,colMax)

n=int(sys.stdin.readline())
candy=list()
for _ in range(n):
    candy.append(list(sys.stdin.readline().rstrip()))

cnt=1
for i in range(n):
    for j in range(n-1):
        if candy[i][j]!=candy[i][j+1]: # 가로로 교환
            candy=swap(candy,i,j,i,j+1)
            cnt=max(cnt,maxCandy(candy,n))
            candy=swap(candy,i,j,i,j+1)
for i in range(n-1):
    for j in range(n):
        if candy[i][j]!=candy[i+1][j]: # 세로로 교환
            candy=swap(candy,i,j,i+1,j)
            cnt=max(cnt,maxCandy(candy,n))
            candy=swap(candy,i,j,i+1,j)
print(cnt)
