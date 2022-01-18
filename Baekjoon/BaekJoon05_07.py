import sys
n=int(input())
for i in range(n):
    a=list(map(int,input().split()))
    student=a[0]
    score=a[1:]
    sum=0
    avg=0
    count=0
    for i in range(student):
        sum=sum+score[i]
    avg=sum/student
    for i in range(student):
        if(score[i]>avg):
            count=count+1
    c=round(count/student*100,3)
    print("%.3f"%c+'%')

