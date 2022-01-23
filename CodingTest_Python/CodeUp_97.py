a,b=map(int,input().split())
arr = []
for i in range(a):
    arr.append([])
    for j in range(b):
        arr[i].append(0)
        
s=int(input())
for i in range(s):
    l,d,x,y=map(int,input().split())
    for j in range(l):
        if(d==0):
            arr[x-1][y-1]=1
            y+=1
        else:
            arr[x-1][y-1]=1
            x+=1
for i in range(a):
    for j in range(b):
        print(arr[i][j],end=" ")
    print()