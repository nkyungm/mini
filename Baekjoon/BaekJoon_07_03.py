L=[]
for i in range(26):
    L.append(-1)
a=map(str,input())
La=list(map(str,a))
for j in range(len(La)):
    if(L[ord(La[j])-97]==-1):
        L[ord(La[j])-97]=j
for k in range(26):
    print(L[k],end=" ")