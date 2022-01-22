n=int(input())
sum=0
i=1
for i in range(n):
    sum+=i
    if(sum>=n):
        print(i)
        break