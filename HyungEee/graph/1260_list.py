import sys
from collections import deque

n,m,v=map(int,sys.stdin.readline().split())
graph=[[]]*(n+1)
for _ in range(m):
    a,b=map(int,sys.stdin.readline().split())
    if not graph[a]:
        graph[a]=[b]
    else:
        graph[a].append(b)
    if not graph[b]:
        graph[b]=[a]
    else:
        graph[b].append(a)

def dfs():
    visited=[False]*(n+1)
    stack=[v]
    while stack:
        value=stack.pop()
        if not visited[value]:
            visited[value]=True
            print(value, end=" ")
            for i in graph[value]:
                if not visited[i]:
                    stack.append(i)
                    
def bfs():
    visited=[False]*(n+1)
    q=deque()
    q.append(v)
    while q:
        value=q.popleft()
        if not visited[value]:
            visited[value]=True
            print(value,end=" ")
            for i in graph[value]:
                if not visited[i]:
                    q.append(i)

for i in graph:
    i.sort(reverse=True)
    # 문제에서 작은 노드를 먼저 방문할 것을 요구하므로
    # dfs에서 스택에 넣을 때 큰 숫자부터 들어가야함.
    # 따라서 내림차순으로 정렬해준다.
dfs()
print()
for i in graph:
    i.reverse()
    # bfs에서는 다시 오름차순으로 정렬해줘야함.
bfs()
