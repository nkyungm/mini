L=[]
L=[0 for _ in range(19)]
for i in range(19):    
	L[i] = list(map(int, input().split()))
n=int(input())
for i in range(n):
  a,b=map(int,input().split())
  a-=1
  b-=1
  for j in range(19):
    if(L[a][j]==0):
      L[a][j]=1
    else:
      L[a][j]=0
  for j in range(19):
    if(L[j][b]==0):
      L[j][b]=1
    else:
      L[j][b]=0
for i in range(19):
    for j in range(19):
        print(L[i][j],end=" ")
    print()
    