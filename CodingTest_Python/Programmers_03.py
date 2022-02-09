def solution(participant, completion):
    dict={} #Dictionary 생성(Hash 제공)
    answer = ''
    for i in participant:
        if(i in dict):
            dict[i]+=1
        else:
            dict[i]=1
    for i in completion:
        if(dict[i]==1):
            del dict[i]
        else:
            dict[i]-=1
    for i in dict:
        answer=i
    return answer