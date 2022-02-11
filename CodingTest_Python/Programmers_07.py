def solution(clothes):
    answer = 1
    count={}
    arr=[]
    for j in range(len(clothes)):
        arr.append(clothes[j][1])
    for i in arr:
        try: count[i] += 1
        except: count[i]=1

    for i in count.values():
        answer*=i+1
    return answer-1 
#(2+1) * (1+1) * (5+1) -1