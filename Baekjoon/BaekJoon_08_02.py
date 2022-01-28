n=int(input())
i=1
a=2
while(1):
    if(n==1):
        print(i)
        break
    elif(a<=n<=a+(i*6)-1):
        print(i+1)
        break
    else:
        a=a+(i*6)
        i+=1
       