import sys

# 풀이 참고: https://chanmuzi.tistory.com/8
# 해를 k라고 했을 때, ex) k=33, m,n,x,y=10,12,3,9
# (k-x)%m=0, (k-y)%n=0이다. ex) 30%10=0, 24%12=0
# 즉, x,y에 각각 m,n을 적절히 더한 것이 k가 된다. ex) 3+10+10+10=33, 9+12+12=33
# (m과 n중 무엇으로 나누어도 나머지가 0이 될때까지 더한다.)

def num(m,n,x,y):
    while x<=m*n: # m*n 까지만 해(k)를 셀 수 있다.
        if (x-y)%n==0: #현재 x의 값을 해(k)라고 가정했을때, (k-y)%n==0가 성립하는지 확인한다.
            return x # 성립한다면 현재 x값이 해(k)이므로 return 한다.
        x+=m # x가 해(k)에 도달할 때까지 m을 더하면서 과정을 반복한다.
    return -1

t=int(sys.stdin.readline())
for _ in range(t):
    m,n,x,y=map(int,sys.stdin.readline().split())
    print(num(m,n,x,y))

# 도저히 안풀려서 다른 사람의 풀이를 참고했음.. 나중에 다시 풀어볼 것,,
