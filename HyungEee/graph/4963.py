import sys

dx=[0,0,1,1,1,-1,-1,-1]
dy=[1,-1,0,1,-1,0,1,-1]

while True:
    w,h=map(int,sys.stdin.readline().split())
    if w==0 and h==0:
        break
    maps=[[] for _ in range(h)]
    for i in range(h):
        maps[i]=list(map(int,sys.stdin.readline().split()))
    
    visited=[[False]*w for _ in range(h)]
    island=0
    for i in range(h):
        for j in range(w):
            if maps[i][j]==1 and not visited[i][j]:
                stackx=[i]
                stacky=[j]
                while stackx:
                    x=stackx.pop()
                    y=stacky.pop()
                    if not visited[x][y]:
                        visited[x][y]=True
                        for k in range(8):
                            nx=x+dx[k]
                            ny=y+dy[k]
                            if 0<=nx<h and 0<=ny<w:
                                if maps[nx][ny]==1 and not visited[nx][ny]:
                                    stackx.append(nx)
                                    stacky.append(ny)
                island+=1
    print(island)
                       
