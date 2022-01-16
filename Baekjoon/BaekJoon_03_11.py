a,b=map(int,input().split())

input_list=list(map(int,input().split()))

for j in range(a):
    if(b>input_list[j]):
        print(input_list[j],end=" ")
