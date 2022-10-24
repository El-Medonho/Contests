import sys

inp = input().split(" ")
n = int(inp[0])
lampadas = int(inp[1])

grid = []

for i in range(lampadas):
    grid.append(0)

inp = input().split(" ")
l = int(inp[0])
for i in range(l):
    grid[int(inp[i+1]) -1] = 1      #settando as lampadas iniciais para acesas

ligacao = []

for i in range(n):
    ligacao.append([])
    inp = input().split(" ")
    for j in range(int(inp[0])):
        ligacao[i].append(int(inp[j+1]) - 1)        #settando quais grid cada interruptor vai ligar


call = 0

def Check():        #checks if there are any lights on 1
    global lampadas
    global grid
    global call

    for i in range(lampadas):
        if grid[i] == 1: return 0
    
    print(call)
    sys.exit()      

for k in range(2):
    for i in range(n):
        call += 1
        for j in ligacao[i]:
            grid[j] = (grid[j] + 1) % 2
        Check()

print(-1)
        


