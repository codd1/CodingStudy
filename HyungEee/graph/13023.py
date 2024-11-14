import sys

n,m=map(int,sys.stdin.readline().split())
graph=[[] for _ in range(n)]
visited=[False]*n
for _ in range(m):
    a,b=map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(idx,depth):
    visited[idx]=True
    if depth==4:
        return True
    else:
        for i in graph[idx]:
            if not visited[i]:
                visited[i]=True
                if dfs(i,depth+1):
                    return True
                visited[i]=False

ans=False
for i in range(n):
    ans=dfs(i,0)
    visited[i]=False
    if ans:
        break
if ans:
    print(1)
else:
    print(0)
