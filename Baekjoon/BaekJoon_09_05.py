import math

def isPrime(a): #에라토스테네스의 체
    if(a<2):
        return False
    for i in range(2,int(math.sqrt(a))+1):
        # 2부터 n의 제곱근까지의 모든 수를 확인
        if(a%i==0):
          return False
    return True
c=0
arr=[]
for j in range(2,123456*2+1):
    if isPrime(j):
        arr.append(j)
while True:
    n=int(input())
    c=0
    if(n==0):
        break
    for i in arr:
        if(i>n)and(i<=2*n):
            c+=1
    print(c)
    