from math import ceil


import math
a,b,v=map(int,input().split())
day=1
h=0
if(a>=v):
    print(day)
else:
    day=ceil((v-a)/(a-b))+1
    print(day)