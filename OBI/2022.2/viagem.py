inp = input().split(" ")
valor = int(inp[0])
nilhas = int(inp[1])
nrotas = int(inp[2])

ilhas = set([])
rotas = []

for i in range(nilhas): 
    ilhas.add(i+1)
    rotas.append({})

for i in range(nrotas):
    inp = input().split(" ")
    ai = int(inp[0])
    bi = int(inp[1])
    ti = int(inp[2])
    pi = int(inp[3])

    if set(rotas[ai-1].keys()).issuperset(set([bi])):
        rotas[ai-1][bi].append([ti, pi])
        rotas[bi-1][ai].append([ti, pi])
    else:
        rotas[ai-1][bi] = [[ti, pi]]
        rotas[bi-1][ai] = [[ti, pi]]

#print(ilhas)
#print(rotas)
#print(rotas[1][1][0])

inp = input().split(" ")
x = int(inp[0])
y = int(inp[1])

#inputs ____________________________

recorde = -1

def Search(blacklist, current, time, price):
    global recorde

    if price > valor: return -1
    if recorde != -1 and time >= recorde: return -1
    if current == y:
#        print(time)
        recorde = time
        return -1
    for i in set(rotas[current-1].keys()).difference(blacklist):
        
        x = blacklist.copy()
        x.add(current)
#        print(current)
#        print(set(rotas[current-1].keys()).difference(blacklist))
        for j in range(len(rotas[current-1][i])):
            Search(x, i, time + rotas[current-1][i][j][0], price + rotas[current-1][i][j][1])

Search(set([]), x, 0, 0)

print(recorde)
