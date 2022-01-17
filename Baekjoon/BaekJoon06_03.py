
def a(n):
    count=0
    if n<100:
        return n
    else:
        for i in range(100,n+1):
            x =i%10
            i /=10
            y = i%10
            z =i/10
            if((x-y)==(y-z)):
                count+=1
        return count

n=int(input())
print(a(n))