import sys

n,m=map(int,sys.stdin.readline().split())
arr=[]
visit=[False]*(n+1)

def dfs(n,m,depth):
    if(depth==m):
        for i in arr:
            print(i,end=" ")
        print()
    for i in range(1,n+1):
        if(not visit[i]):
            visit[i]=True
            arr.append(i)
            dfs(n,m,depth+1)
            visit[i]=False;
            arr.pop(-1)

dfs(n,m,0)

# depth=0, arr=[]에서 시작
# 다음 노드를 방문=>방문한 노드 arr[depth]에추가, 방문처리, depth++ => 하위노드 방문
# arr.length==depth일 시 화면에 출력.
# 이전 노드로 되돌아감(이전노드 방문처리 해제, arr의 마지막요소 삭제) => 다음노드 방문 반복