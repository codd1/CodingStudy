import sys
from collections import deque

n=int(sys.stdin.readline())
houses=[[] for _ in range(n)]
for i in range(n):
    houses[i]=list(map(int,sys.stdin.readline().rstrip()))
graph=[[[] for _ in range(n)] for _ in range(n)]

# 연결관계 정리
for i in range(n):
    for j in range(n):
        if houses[i][j]==1:
            if i<n-1 and houses[i+1][j]==1:
                graph[i][j].append([i+1,j])
            if j<n-1 and houses[i][j+1]==1:
                graph[i][j].append([i,j+1])
            if i>=1 and houses[i-1][j]==1:
                graph[i][j].append([i-1,j])
            if j>=1 and houses[i][j-1]==1:
                graph[i][j].append([i,j-1])
                
visited=[[False]*n for _ in range(n)]
complexs=[]

# 단지 구하기
for i in range(n):
    for j in range(n):
        q=deque()
        if houses[i][j]==1 and not visited[i][j]:
            q.append(i)
            q.append(j)
            count=0
            while q:
                x=q.popleft()
                y=q.popleft()
                if not visited[x][y]:
                    visited[x][y]=True
                    count+=1
                    for k in graph[x][y]:
                        q.append(k[0])
                        q.append(k[1])
            complexs.append(count)
complexs.sort()
print(len(complexs),*complexs,sep="\n")
