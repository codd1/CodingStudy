import sys

n=int(sys.stdin.readline())
house=[[0,0,0] for _ in range(n)]

for i in range(n):
    house[i]=list(map(int,sys.stdin.readline().split()))

rgb=[[0]*3 for _ in range(n)] # 0:R, 1:B, 2:G
rgb[0][0],rgb[0][1],rgb[0][2]=house[0][0],house[0][1],house[0][2]
for i in range(1,n):
    rgb[i][0]=min(rgb[i-1][1]+house[i][0],rgb[i-1][2]+house[i][0])
    #현재 타일이 R일때의 최솟값=min(이전타일이 B일때,이전 타일이 G일때)
    rgb[i][1]=min(rgb[i-1][0]+house[i][1],rgb[i-1][2]+house[i][1])
    #현재 타일이 G일때의 최솟값=min(이전타일이 R일때,이전 타일이 B일때)
    rgb[i][2]=min(rgb[i-1][0]+house[i][2],rgb[i-1][1]+house[i][2])
    #현재 타일이 B일때의 최솟값=min(이전타일이 R일때,이전 타일이 G일때)

print(min(rgb[n-1]))
