number=[0 for i in range(42)]
count=0
for i in range(10):
    a=int(input())
    num=a%42
    number[num]=number[num]+1

for i in range(42):
    if(number[i]!=0):
        count=count+1
print(count)