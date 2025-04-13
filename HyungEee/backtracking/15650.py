import sys

n,m=map(int,sys.stdin.readline().split())
arr=[]
visit=[False]*(n+1)

def dfs(depth):
    if(depth==m):
        for i in arr:
            print(i,end=" ")
        print()
        
    if arr:
        k=arr[-1] # arr에 추가된 요소가 없다면 for문의 시작을 1로 함
    else:
        k=1 # 추가된 요소가 있다면 배열의 마지막 요소를 for문의 시작으로 함
    # (오름차순인 수열을 만들기 위한 과정)
    
    for i in range(k,n+1):
        if(not visit[i]):
            arr.append(i)
            visit[i]=True
            dfs(depth+1)
            visit[i]=False
            arr.pop(-1)
dfs(0)
# depth=0, arr=[]에서 시작
# 다음 노드를 방문=>방문한 노드 arr[depth]에추가, 방문처리, depth++ => 하위노드 방문
# arr.length==depth일 시 화면에 출력.
# 이전 노드로 되돌아감(이전노드 방문처리 해제, arr의 마지막요소 삭제) => 다음노드 방문 반복
