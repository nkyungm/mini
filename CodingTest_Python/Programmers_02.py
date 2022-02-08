def solution(array, commands):
    answer = []
    a=[]
    for ii in range(len(commands)):
        i=commands[ii][0]-1
        j=commands[ii][1]
        k=commands[ii][2]-1
        a=sorted(array[i:j])
        answer.append(a[k])
    return answer