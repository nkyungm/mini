def solution(n, lost, reserve):
    answer = 0
    res=set(reserve)-set(lost)
    los=set(lost)-set(reserve)
    #여벌 체육복을 가져온 학생이 도난 당한 경우 제외
    for i in res:
        if(i-1 in los):
            los.discard(i-1)
        elif(i+1 in los):
            los.discard(i+1)
    answer=n-len(los)
    return answer
print(solution(5,[2, 5],[2, 4]))