a=input()
b=input()
int_a=int(a)
int_b=int(b)
t=int_b
b_1=int_b//100
int_b-=b_1*100
b_2=int_b//10
b_3=int_b-b_2*10
print(b_3*int_a)
print(b_2*int_a)
print(b_1*int_a)
print(int_a*t)