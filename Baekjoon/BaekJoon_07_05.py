a=input()
alpha=[]
for j in range(27):
    alpha.append(0)
for i in range(len(a)):
    k=a[i].upper()
    alpha[ord(k)-65]+=1

m=max(alpha)
for k in range(alpha.index(m)+1,27):
    if(m==alpha[k]):
        g=1
        break
    else:
        g=2

if(g==1):
    print("?")
else:
    print(chr(alpha.index(m)+65))