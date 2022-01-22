n=int(input())
L=[]
for i in range(20):
    L.append([])
    for j in range(20):
        L[i].append(0)
for i in range(n):
    a,b=map(int,input().split())
    L[a][b]=1
for i in range(1,20):
    for j in range(1,20):
        print(L[i][j],end=" ")
    print()    