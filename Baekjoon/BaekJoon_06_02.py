n=set(range(1,10001))
gn=set()

for i in range(1,10001):
    for j in str(i): #입력되는 i를 str(문자열)로 바꿔줘서 850면 8,5,0을 떼줌
        i+=int(j) #850+8+5+0 =863 
    gn.add(i)

sn=sorted(n-gn)
for i in sn:
    print(i)