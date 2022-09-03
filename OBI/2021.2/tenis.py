t1 = []
t1.append(int(input()))
t1.append(int(input()))
t1.append(int(input()))
t1.append(int(input()))

j1 = min(t1)
j2 = max(t1)
t1.pop(t1.index(j1))
t1.pop(t1.index(j2))
dif = abs((j1+j2)-(t1[0]+t1[1]))
print(dif)