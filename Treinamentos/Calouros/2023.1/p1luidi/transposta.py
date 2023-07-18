matriz = eval(input())

nova = []

for j in range( len(matriz[0]) ):
    nova.append([])
    for i in range( len(matriz) ):
        nova[-1].append( matriz[i][j] )

# nova é a matriz transposta

print(nova)

for i in range( len(nova) ):
    for j in nova[i]:
        print(j, end = ' ')
    print()

    
# [[0,1,2],[3,4,5]]

# 0 1 2
# 3 4 5