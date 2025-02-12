import sys
from collections import deque

dx=[0,0,1,-1]
dy=[1,-1,0,0]

n,m=map(int,sys.stdin.readline().split())
miro=[]
for i in range(n):
    miro.append(list(map(int,sys.stdin.readline().rstrip())))

q=deque()
q.append((0,0))

while q:
    x,y=q.popleft()
    for k in range(4):
        nx=x+dx[k]
        ny=y+dy[k]
        if 0<=nx<n and 0<=ny<m:
            if miro[nx][ny]==1:
                q.append((nx,ny))
                miro[nx][ny]=miro[x][y]+1 # 이동 횟수를 miro 배열에 저장한다.
                
print(miro[n-1][m-1])
