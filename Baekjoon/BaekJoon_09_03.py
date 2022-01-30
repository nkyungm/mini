def star(x,y):
    if(((x%3)==1)and((y%3)==1)):
        return 1
    if(x==0 or y==0):
        return 0
    return star(x/3,y/3)

n=int(input())
for i in range(n):
    for j in range(n):
        if(star(i,j)):
            print(" ",end="")
        else:
            print("*",end="")
    print(" ")