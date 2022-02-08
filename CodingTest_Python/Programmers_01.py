def solution(answers):
    a1=[1,2,3,4,5]
    a2=[2,1,2,3,2,4,2,5]
    a3=[3,3,1,1,2,2,4,4,5,5]
    answer = []
    count1=0
    count2=0
    count3=0
    
    for i in range(len(answers)):
        if(a1[i%len(a1)]==answers[i]):
            count1+=1
            
    for i in range(len(answers)):
        if(a2[i%len(a2)]==answers[i]):
            count2+=1
            
    for i in range(len(answers)):
        if(a3[i%len(a3)]==answers[i]):
            count3+=1 
    
    if(count1>=count2 and count1>=count3):
        answer.append(1)
    if(count2>=count1 and count2>=count3):
        answer.append(2)
    if(count3>=count1 and count3>=count2):
        answer.append(3)
               
    return answer