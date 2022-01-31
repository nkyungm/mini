m=int(input())
n=int(input())
count=0
c=0
a=[]
b=[]
for k in range(m,n+1):
    a.append(k)

for i in range(n-m+1):
    c=0
    if(a[i]==1):
        continue
    for j in range(2,a[i]):
        if(a[i]%j==0 ):
            c+=1
        if(c!=0):
            break
    if(c==0):
        b.append(a[i])

if(sum(b)!=0):
    print(sum(b))
    print(min(b))
else:
    print("-1")

