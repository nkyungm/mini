n=input()
sum=0
a=['c=','c-','dz=','d-','lj','nj','s=','z=']
for i in a:
    num=n.count(i)
    n.replace(i,"")
    sum+=num
sum=len(n)-sum
print(sum)