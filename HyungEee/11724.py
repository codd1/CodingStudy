import sys
from collections import deque

n,m=map(int,sys.stdin.readline().split())
graph=[[0]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,sys.stdin.readline().split())
    graph[a][b]=graph[b][a]=1
visited=[False]*(n+1)
ans=0

for i in range(1,n+1):
    q=deque()
    if not visited[i]:
        q.append(i)
        while q:
            value=q.popleft()
            if not visited[value]:
                visited[value]=True
                for j in range(1,n+1):
                    if graph[value][j]==1:
                        q.append(j)
        ans+=1
    
print(ans)
    
