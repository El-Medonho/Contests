t = int(input())
n = []
k = []
for i in range(t):
    n.append(int(input()))
    k.append([])
    k[i] = input().split()

for j in range(t):
    sum = 0
    possible = True
    for u in range(n[j] - 1):
        i = n[j] - 1 - u
        p = int(k[j][i])
        q = int(k[j][i-1])
        if p < i: 
                possible = False
                break
        while(p <= q):
           q = q // 2
           sum += 1
        k[j][i-1] = q
    if possible: print(sum)
    else: print(-1)
