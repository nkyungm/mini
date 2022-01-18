import sys

n=int(input())
for i in range(n):
    b=list(sys.stdin.readline().strip())
    count=0
    ccount=0
    for j in range(len(b)):
        if b[j]=='O':
            count=count+1
            ccount=ccount+count
        else:
            count=0
    print(ccount)