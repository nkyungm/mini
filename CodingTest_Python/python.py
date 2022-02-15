count={}
lists = ["headgear", "eyewear","headgear"]
for i in lists:
    try: count[i] += 1
    except: count[i]=1
print(count)

a = [1, 2, 3, 4, 5]
b = [5, 6, 7, 8, 9]
c = [x + y for x, y in zip(a,b)]
print(c)
