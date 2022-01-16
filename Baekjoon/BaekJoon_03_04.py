import sys
n=int(sys.stdin.readline())
a_list=[]
b_list=[]
for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    a_list.append(a)
    b_list.append(b)

for i in range(n):
    print(a_list[i]+b_list[i])