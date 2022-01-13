H,M=map(int,input().split())
if(M>=45):
    change_M=M-45
    change_H=H
else:
    if(H>0):
        change_H=H-1
        change_M=(60+M)-45
    else:
        change_H=23
        change_M=(60+M)-45
print(change_H,change_M)

