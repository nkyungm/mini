def solution(progresses, speeds):
    answer = []
    coun=[]
    c=0
    while(progresses!=[]):
        progresses=[x+y for x,y in zip(progresses,speeds)]
        c+=1
        while(1):
            if(len(progresses)!=1):
                if (progresses[0]>=100):
                    coun.append(c)
                    progresses.pop(0)
                    speeds.pop(0) 
                else:
                    break
            else:
                if(progresses[0]<=100):
                    break
                coun.append(c)
                progresses.pop(0)
                speeds.pop(0)    
                break
            
    answer.append(coun.count(coun[0]))
    for i in range(1,len(coun)):
        if(coun[i-1]!=coun[i]):
            answer.append(coun.count(coun[i]))
               
    return answer