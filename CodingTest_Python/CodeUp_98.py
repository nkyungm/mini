arr=[0 for _ in range(10)]
for i in range(10):
    arr[i]=list(map(int,input().split()))
row=1
col=1
while True:
    if(arr[row][col+1]==0):
        arr[row][col]=9
        col+=1
    elif(arr[row][col+1]==1):
        if(arr[row+1][col]==0):
            arr[row][col]=9
            row+=1
        elif(arr[row+1][col]==1):
            arr[row][col]=9
            break
        else:
            arr[row][col]=9
            arr[row+1][col]=9
            break
    else:
        arr[row][col]=9
        arr[row][col+1]=9
        break
for i in range(10):
    for j in range(10):
        print(arr[i][j],end=" ")
    print() 