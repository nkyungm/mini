origin_n=int(input())
count=0
if(int(origin_n)<10):
    origin_n=str(origin_n)+'0'
n=origin_n
while True:
    int_n=int(n)
    n_2=int_n%10
    int_n=int_n//10
    n_1=int_n
    int_n=n_1+n_2
    if(int_n>=10):
        int_n=int_n%10
    n=n_2*10+int_n
    count=count+1
    if(n==int(origin_n)):
        print(count)
        break