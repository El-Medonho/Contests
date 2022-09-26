import math

n = int(input())
nomes = []
notas = []
res = []
for i in range(n):
    nomes.append(input())
    notas.append((input().split(" ")))
    for j in range(len(notas[i])
    ):
        notas[i][j] = float(notas[i][j])

for i in range(n):
    if len(notas[i]) == 1: res.append(round((notas[i][0])/2, 1))
    elif len(notas[i]) == 2: res.append(round((notas[i][0] + notas[i][1])/2, 1))
    elif len(notas[i]) == 3: res.append(round((notas[i][0] + notas[i][1] + notas[i][2])/3, 1))
    else: res.append(round((notas[i][0] + notas[i][1] + notas[i][2] + notas[i][3] - min(notas[i][0], notas[i][1], notas[i][2],notas[i][3]))/3, 1))

for i in range(n):
    print(nomes[i] + ": " + str(res[i]))

