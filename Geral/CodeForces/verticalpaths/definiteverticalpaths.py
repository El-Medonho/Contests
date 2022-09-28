t = int(input())
n = []
p = []
for i in range(t):
    n.append(int(input()))
    p.append(input().split(" "))

def Exception(i):
    print(1)
    print(1)
    print(p[i][0])
    print()

for i in range(t):
    quantity = []
    blacklist = [] 
    root = 0
    ways = []
    ended = False
    CurrentStop = 0
    k = 0
    for j in range(n[i]):
        quantity.append(0)
        blacklist.append(True)
    for j in range(n[i]):
        b = int(p[i][j])
        if b == j + 1: root = j + 1 #112 root is 1, j = 0
        quantity[b - 1] += 1
    if len(quantity) == 1: Exception(i); continue
    for j in range(len(quantity)):
        if quantity[j] == 0:
            ways.append([])
            ended = False
            CurrentStop = j + 1
            while not ended:
                if blacklist[CurrentStop - 1]:
                    blacklist[CurrentStop - 1] = False
                    ways[k].append(CurrentStop)
                    CurrentStop = int(p[i][CurrentStop - 1])
                else:
                    k += 1
                    break
    print(len(ways))
    for j in range(len(ways)):
        print(len(ways[j]))
        for m in range(len(ways[j])):
            print(ways[j].pop(), end= " ")
        print()
    print()
