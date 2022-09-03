n = int(input())
piramide = []
for i in range(n):
    piramide.append([])
    for j in range(n):
        piramide[i].append(0)
n = n-1
for i in range(n+1):
    k = i
    if k > n//2: k = n-k
    for j in range(n+1):
        l = j
        if l > n//2: l = n-l
        piramide[i][j] = min(k,l)+1
        

for i in range(n+1):
    for j in range(n+1):
        print(piramide[i][j], end = " ")
    print()