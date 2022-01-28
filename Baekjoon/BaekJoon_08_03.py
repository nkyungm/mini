n=int(input())
start=1
end=1
sum=0
for i in range(1,n+1):
    sum+=i
    if(sum>=n):
        start=i
        end=n-(sum-i)
        break
a=0
b=0
if start%2!=0:
    a=start+1
    b=0
    
    for j in range(end):
        a-=1
        b+=1

elif start%2==0:
    a=0
    b=start+1
    
    for j in range(end):
        b-=1
        a+=1

print("{}/{}".format(a,b))