n=int(input())
for i in range(n):
    a,b=map(str,input().split())
    for j in range(len(b)):
        print(b[j]*int(a),end="")
    print()