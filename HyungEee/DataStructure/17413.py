import sys

s=list(sys.stdin.readline().rstrip())
news=list()

i=0
while i<=len(s)-1:
    if s[i]=="<":
        while s[i]!=">":
            news.append(s[i])
            i+=1
        news.append(">")
    else:
        word=list()
        while i<=len(s)-1:
            if s[i]=="<":
                i-=1
                break
            elif s[i]==" ":
                word.insert(0," ")
                break
            word.append(s[i])
            i+=1
        word.reverse()
        news=news+word
    i+=1
            
print(*news,sep="")
