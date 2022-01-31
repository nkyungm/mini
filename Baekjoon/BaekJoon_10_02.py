def pivo(n):
    if(n==0):
        return 0
    elif(n==1):
        return 1
    else:
        return pivo(n-2)+pivo(n-1)
n=int(input())
print(pivo(n))