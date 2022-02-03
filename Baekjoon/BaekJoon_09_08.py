import math
arrx=[]
arry=[]
for i in range(3):
    x,y=map(int,input().split())
    arrx.append(x)
    arry.append(y)

a=arrx[0]
b=arry[0]
for j in range(1,3):
    if(a!=arrx[1] and a!=arrx[2]):
        print(a,end=" ")
        break
    elif(a!=arrx[j]):
        print(arrx[j],end=" ")
        break

for k in range(1,3):
    if(b!=arry[1] and b!=arry[2]):
        print(b,end=" ")
        break
    elif(b!=arry[k]):
        print(arry[k],end=" ")
        break