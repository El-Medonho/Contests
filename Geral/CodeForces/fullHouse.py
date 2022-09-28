a = 0
b = 0
penis = {}
c = input().split(" ")
sit = set(c)
if len(sit) == 2:
    for i in sit:
        penis[i] = 0
    for i in range(5):
        penis[c[i]] += 1
    for i in sit:
        if penis[i] == 2 or penis[i] == 3: print("Yes")
        else: print("No")
        break
else: print("No")
