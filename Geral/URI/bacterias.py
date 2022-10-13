from functools import reduce
import sys


def mod(a):
    ret = a%13371337
    if ret<0: ret+= 13371337
    return ret

def mult_matriz(A,B):
    C = []
    for i in range(len(A)):
        C.append([])
        for j in range(len(B[0])):
            sum = 0
            for k in range(len(A[0])):
                sum += mod(mod(A[i][k]) * mod(B[k][j]))
            C[i].append(mod(sum))
    return C


ans = []

while True:
    n = int(input())
    if n == 0: break
    n-=4


    inp = list(map(int,input().split()))

    quarto = reduce(lambda x,y: x+y, inp)
    A = [[1,1,1,1],[1,0,0,0],[0,1,0,0],[0,0,1,0]]
    base = [[quarto], [inp[3]], [inp[2]], [inp[1]]]
    U = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]


    digits = []
    while n>1:
        digits.append(n%2)
        n = n//2
    digits.append(n)

    for i in digits:
        if i == 1:
            U = mult_matriz(U,A)
            # for j in range(9): U[j//3][j%3] = mod(U[j//3][j%3])
        A = mult_matriz(A,A)
        # for j in range(9): A[j//3][j%3] = mod(A[j//3][j%3])

    U = mult_matriz(U,base)
    ans.append((U[0][0]))
    # ans.append(int(U[0][0]))

for i in range(len(ans)): print(ans[i])