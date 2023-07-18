
inp = eval(input())     #matriz NxN, onde n >= 4

def matrizx3 (C):
    a = C[0][0]
    b = C[0][1]
    c = C[0][2]
    d = C[1][0]
    e = C[1][1]
    f = C[1][2]
    g = C[2][0]
    h = C[2][1]
    i = C[2][2]

    resultado = (((a*e*i) + (b*f*g) + (c*d*h)) - ((a*f*h) + (b*d*i) + (c*e*g)))
    return resultado

def matrizxn (matriz):
    n = len(matriz)
    if(n <= 3): return matrizx3(matriz)

    #vamos selecionar os elementos (0,0) -> (0,n-1)

    ans = 0

    for i in range(n):      # Passo 1
        x = 0
        y = i

        nova = []       #Passo 2

        for ii in range(n):     # formando a matriz
            if(ii == x): continue
            nova.append([])

            for jj in range(n):
                if(jj == y): continue
                nova[-1].append(matriz[ii][jj])
                nova[ len(nova) - 1 ].append(matriz[ii][jj])

        ans += matriz[0][i] * matrizxn(nova) * ( (-1) ** (i+2) )        #Passo 3

    return ans
    
print(matrizxn(inp))

# 0 1 0 1 0
# 1 0 1 0 1
# 0 1 0 1 0 
# 1 0 1 0 1
# 0 1 0 1 0

