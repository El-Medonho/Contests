inp = list(map(int,input().split()))
t = inp[0]
m = inp[1]
Ai = list(map(int,input().split()))
Ai.sort()
S = Ai[-1]
Ai.pop()

def mult_matriz(A,B):
    C = []
    for i in range(len(A)):
        C.append([])
        for j in range(len(B[0])):
            sum = 0
            for k in range(len(B)):
                sum += A[i][k]*B[k][j]
            C[i].append(sum)
    return C

def calculate(s):
    global t
    if s < 2: return s
    if s == 2: return 1
    s-=1
    U = [[1,0],[0,1]]
    A = [[1,-t],[1,0]]
    base = [[1],[0]]

    digits = []
    while s>1:
        digits.append(s%2)
        s//=2
    digits.append(s)

    for i in digits:
        if i == 1:
            U = mult_matriz(U,A)
        A = mult_matriz(A,A)
    
    # U = mult_matriz(U,base)
    return U[0][0]

sumS = 0
for i in range(S+1):
    sumS += calculate(i)
for i in Ai:
    sumS -= calculate(i)

print(sumS%1000000009)
