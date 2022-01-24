n=int(input())
sum=0
a=list(map(int,input().split()))
b=[0 for i in range(n)]
for i in range(n):
    b[i]=(a[i]/max(a))*100
    sum=sum+b[i]
print(sum/n)
