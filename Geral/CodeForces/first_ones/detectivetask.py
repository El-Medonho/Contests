t = int(input())
s = []
for i in range(t): s.append(input())
for j in range(t):
    u = s[j]
    m = len(u)
    sum = 0
    ha_um = False
    for i in range(m):
        c = u[i]
        if c == "1":
            sum = 0
            ha_um = True
        elif ( c == "?"): sum += 1
        else: 
            sum += 1
            break
    if ha_um: sum += 1
    print(sum)