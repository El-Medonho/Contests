n = 600000
primos = set([])

def Magic(i):
    return int(i//(i**(1/2))) + 1

def Check(i,m):
    index = 0
    if i <= 1: return 0
    if i >= 2: primos.add(2)
    if i >=3 : primos.add(3)
    for j in range(m-1):
        if i%(j+1) == 0: index += 1
        if index > 1: return 0
    print(i)
    return 0


for i in range(n):
    if i <= 1: continue
    m = Magic(i)
    Check(i,m)