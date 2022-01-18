sum=1
for i in range(3):
    n=int(input())
    sum=sum*n
str_n=str(sum)
#number=[0,0,0,0,0,0,0,0,0,0]
number=[0 for i in range(10)]

for i in range(len(str_n)):
    k=int(str_n[i])
    number[k]=number[k]+1

for i in range(10):
    print(number[i])
