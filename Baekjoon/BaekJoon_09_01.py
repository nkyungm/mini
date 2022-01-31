n=int(input())
count=0
c=0
a=list(map(int,input().split()))
for i in range(n):
    c=0
    if(a[i]==1):
        continue
    for j in range(2,a[i]):
        if(a[i]%j==0):
            c+=1
    if(c==0):
        count+=1
print(count)