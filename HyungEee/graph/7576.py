import sys
from collections import deque

dx=[0,0,1,-1]
dy=[1,-1,0,0]

m,n=map(int,sys.stdin.readline().split())
box=[]
for i in range(n):
    box.append(list(map(int,sys.stdin.readline().split())))

q=deque()
for i in range(n):
    for j in range(m):
        if box[i][j]==1:
            q.append((i,j))
            
while q:
    x,y=q.popleft()
    for k in range(4):
        nx=x+dx[k]
        ny=y+dy[k]
        if 0<=nx<n and 0<=ny<m:
            if box[nx][ny]==0:
                box[nx][ny]=box[x][y]+1 # 이동횟수를 box 배열에 저장한다
                q.append((nx,ny))
success=True
for i in range(n):
    for j in range(m):
        if box[i][j]==0:
            success=False
            break
if not success:
    print(-1)
else:
    print(max(map(max,box))-1) # box에 저장된 이동횟수에는 초깃값 1이 더해진 상태이므로 1을 빼줘야함
