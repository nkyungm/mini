n=int(input())
L=list(map(int,input().split()))
num_L=[]
for i in range(24):
    num_L.append(0)
for i in range(n):
    num_L[L[i]]+=1
for i in range(1,24):
    print(num_L[i],end=" ")