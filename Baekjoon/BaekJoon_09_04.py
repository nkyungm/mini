from ast import Return
import math
def is_prime_num(n):
   arr=[True for i in range(n+1)]
   for i in range(2,int(math.sqrt(n))+1):
       if(arr[i]==True):
           j=2
           while(i*j<=n):
               arr[i*j]=False
               j+=1
    return [i for i in range(2,n+1) if arr[i]]

m,n=map(int,input().split())
a=is_prime_num(m-1)
arr=is_prime_num(n)
for j in range(len(a)):
    arr.remove(a[j])
for i in range(len(arr)):
    if arr[i]==False:
        print(i)