a_list=[]
b_list=[]
i=0
a,b=map(int,input().split())
a_list.append(a)
b_list.append(b)
while((a!=0)and(b!=0)):
    a,b=map(int,input().split())
    a_list.append(a)
    b_list.append(b)
while(i<len(a_list)-1):
    print(a_list[i]+b_list[i])
    i=i+1

