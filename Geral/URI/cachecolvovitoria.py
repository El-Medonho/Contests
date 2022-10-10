

n = int(input())
n = n-1

A = [[3,2],[2,2]]
base = [6,6]

def mult_matriz(A,B):
    C = []
    for i in range(len(A[0])):
        C.append([])
        for j in range(len(B)):
            sum = 0
            for k in range(len(B)):
                sum += A[i][k] * B[k][j]
            C[i].append(sum)

    # for i in range(4): C[i//2][i%2] %= 1e9+7
    return C

def getmat(A,n):
    U = [[1,0],[0,1]]
    digits = []
    while n>1:
        q = n%2
        digits.append(q)
        n //= 2
    digits.append(n)
    
    for i in digits:
        if i == 1: 
            U = mult_matriz(U,A); 
            for i in range(4): U[i//2][i%2] %= 1000000007
        A = mult_matriz(A,A)
        for i in range(4): A[i//2][i%2] %= 1000000007

    sum = U[0][0] + U[0][1] + U[1][0] + U[1][1]
    sum*=6
    print(int(sum%(1000000007)))

getmat(A,n)