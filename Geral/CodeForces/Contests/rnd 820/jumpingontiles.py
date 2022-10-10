t = int(input())

for g in range(t):
    s = input()
    n = len(s)
    occur = []
    casas = []
    for i in range(26):
        occur.append(0)
        casas.append([])
    inicio = s[0]
    final = s[-1]
    way = abs(ord(inicio)-ord(final))
    ck = ord("a")

    for i in range(n):
        current = s[i]
        occur[ord(current)-ck] += 1
        casas[ord(current)-ck].append(i)

    if inicio == final: 
        print(str(way) + " " + str(occur[ord(inicio) - ck]))
        for i in casas[ord(inicio)-ck]: print(i+1, end = " ")
        print()
        continue

    direction = 1
    if ord(final)-ord(inicio) < 0: direction = -1
    sum = 0
    for i in range(way+1):
        j = i*direction
        sum += occur[ord(inicio) - ck + j]
    print(str(way) + " " + str(sum))
    for i in range(way+1):
        k = i*direction
        for j in (casas[ord(inicio) - ck + k]):
            print(j+1, end = " ")
    print() 
