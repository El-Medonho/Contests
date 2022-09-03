n = int(input()) #dimensao do quadrado
quadrado = []
for i in range(n): quadrado.append(input().split(" "))
m = 0 #linha
n = 0 #coluna
for j in range(len(quadrado)):
    for k in range(len(quadrado)):
        if int(quadrado[j][k]) == 0:
            m = j+1
            n = k+1
soma = 0
soma2 = 0

if m-1 != 0:
    for l in range(len(quadrado)): soma += int(quadrado[0][l])
else:
    for b in range(len(quadrado)): soma += int(quadrado[1][b])
        
for c in range(len(quadrado)): soma2 += int(quadrado[m - 1][c])
print(soma - soma2)
print(m)
print(n)




