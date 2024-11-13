import sys
from collections import deque

n,m,v=map(int,sys.stdin.readline().split())
graph=[[0]*(n+1) for _ in range(n+1)]
for i in range(m):
    a,b=map(int,sys.stdin.readline().split())
    graph[a][b]=1
    graph[b][a]=1

def dfs(graph,n,v):
    visited=[False]*(n+1)
    stack=[v]
    while stack:
        value=stack.pop()
        if not visited[value]:
            print(value,end=" ")
            visited[value]=True
        for i in range(n,-1,-1):
            if graph[value][i]==1 and not visited[i]:
                # 문제에서 작은 숫자부터 입력하기를 요구하므로 반대로 순회함.
                # 순차적으로 하면 스택에 2,3,4 순으로 입력되고 4부터 pop되어 가장 큰 수인 4부터 pop되기 때문.
                stack.append(i)
    print()       

def bfs(graph,n,v):
    visited=[False]*(n+1)
    queue=deque()
    queue.append(v)
    while queue:
        value=queue.popleft()
        if not visited[value]:
            print(value,end=" ")
            visited[value]=True
            for i in range(1,n+1):
                if graph[value][i]==1 and not visited[i]:
                    queue.append(i)        

dfs(graph,n,v)
bfs(graph,n,v)
