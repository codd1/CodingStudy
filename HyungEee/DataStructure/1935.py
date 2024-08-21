import sys

n=int(sys.stdin.readline())
input=list(sys.stdin.readline().rstrip())
alp=list()
st=list()

for i in range(n):
    alp.append(int(sys.stdin.readline()))

for i in input:
    if i>='A' and i<='Z':
        st.append(alp[ord(i)-65])
    else:
        op1=st.pop()
        op2=st.pop()
        if i=="+":
            st.append(op1+op2)
        elif i=="-":
            st.append(op2-op1)
        elif i=="*":
            st.append(op1*op2)
        else:
            st.append(op2/op1)
print(format(st[-1],".2f"))
