n=int(input())
sum=0
for i in range(n):
    a=input()
    box=[]
    box.append(a[0])
    for j in range(1,len(a)):
        if(a[j-1]!=a[j]):
            if(a[j] in box):
                sum-=1
                break
            else:
                box.append(a[j])
        else:
            if(a[j] in box):
                continue
            else:
                box.append(a[j])
    sum+=1
print(sum)
    