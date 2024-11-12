import sys
sys.setrecursionlimit(10**6)
# 최대 재귀 깊이를 변경해주어야 RecursionError가 발생하지 않음

n,m=map(int,sys.stdin.readline().split())
graph=[[0]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,sys.stdin.readline().split())
    graph[a][b]=graph[b][a]=1
ans=0
visited=[False]*(n+1)

def dfs(x):
    visited[x]=True
    for i in range(1,n+1):
        if graph[x][i]==1 and not visited[i]:
            dfs(i)

for i in range(1,n+1):
    if not visited[i]:
        dfs(i)
        ans+=1

print(ans)
