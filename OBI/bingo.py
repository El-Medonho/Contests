inp1 = input().split(" ")
n = int(inp1[0]) #numero de cartelas
k = int(inp1[1]) #numeros cada cartela contem
u = int(inp1[2]) #maior natural em uma cartela

cartelas = []
for i in range(n):
    cartelas += [[]] 
    cartelas[i] += input().split(" ")
    cartelas[i].sort()

sorteados = input().split(" ")

soma = []

for i in range(n):
    soma.append(0)

a = 0
b = 0

def BuscaBinaria(v,x):
    global a; global b
    if a > b: return -1
    m = (a + b)// 2
    if v[m] > x: b = m - 1; return BuscaBinaria(v,x)
    elif v[m] < x: a = m + 1; return BuscaBinaria(v,x)
    elif v[m] == x: return m

verifier = True
winners = []

for i in sorteados:
    if verifier:
        for j in range(len(cartelas)):
            a = 0
            b = len(cartelas[j]) - 1
            u = BuscaBinaria(cartelas[j], i)
            if u != -1: soma[j] = soma[j] + 1

        for j in range(len(soma)):
            if soma[j] == k:
                winners.append(j+1)
                verifier = False 

answer = ""

for i in winners: answer = answer + str(i) + " "
print(answer)