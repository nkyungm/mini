number=input()
count=0
for i in range(len(number)):
    if('A'<=number[i]<='C'):
        count+=3
    elif('D'<=number[i]<='F'):
        count+=4
    elif('G'<=number[i]<='I'):
        count+=5
    elif('J'<=number[i]<='L'):
        count+=6
    elif('M'<=number[i]<='O'):
        count+=7
    elif('P'<=number[i]<='S'):
        count+=8
    elif('T'<=number[i]<='V'):
        count+=9
    elif('W'<=number[i]<='Z'):
        count+=10
print(count)