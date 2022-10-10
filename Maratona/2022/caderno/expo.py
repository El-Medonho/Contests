n = 10                          #expoente da matriz
A = [[1,2,3][1,0,0][0,1,0]]     #matriz molde
U = [[1,0,0],[0,1,0],[0,0,1]]   #matriz identidade
base = [[1][4][3]]              #matriz multiplicada ao final
MOD = 1000000009                #questao provavelmente vai pedir o resultado com um mod

def mult_matriz(X,Y):
    Z = []
    for i in range(len(X)):
        Z.append([])
        for j in range(len(Y[0])):
            sum = 0
            for k in range(len(X[0])):
                sum += X[i][k] * Y[k][j]
            Z[i].append(sum)
    return Z

# transformar n em binario para realizar a exponenciação
digits = []
while n>1:
    digits.append(n%2)
    n //= 2
digits.append(n)

#exponenciação da matriz U
for i in digits:
    if i == 1:
        U = mult_matriz(U,A)
        #for i in range(len(U)**2): U[i//len(U)][i%len(U)] %= MOD
    A = mult_matriz(A,A)
    #for i in range(len(A)**2): A[i//len(A)][i%len(A)] %= MOD

U = mult_matriz(U,base)

answer = U[0][0]%MOD    #provavelmente a questao vai pedir f(n)