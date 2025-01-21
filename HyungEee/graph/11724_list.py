import sys
from collections import deque

# 이 문제에서는 간선 없이 정점 한 개로만 이루어진 것도 하나의 연결요소로 본다!
# 위 사실을 몰라서 계속 틀렸음..

n,m,=map(int,sys.stdin.readline().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,sys.stdin.readline().split())
    if not graph[u]:
        graph[u]=[v]
    else:
        graph[u].append(v)
    if not graph[v]:
        graph[v]=[u]
    else:
        graph[v].append(u)
visited=[False]*(n+1)
ans=0

for i in range(1,n+1):
    if not visited[i]:
        q=deque()
        q.append(i)
        while q:
            top=q.popleft()
            if not visited[top]:
                visited[top]=True
                for j in graph[top]:
                    q.append(j)
        ans+=1
print(ans)
        
