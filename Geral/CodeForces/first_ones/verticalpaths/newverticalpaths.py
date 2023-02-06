t = int(input())
n = []
p = []
for i in range(t):
    n.append(int(input()))
    p.append(input().split(" "))



def Search(num,i,index,create_new):
    first = True
    if create_new:
        ways[index].append(num)
    else:
        ways.append([num])
    for j in range(n[i]):
        if int(p[i][j]) == num:
            if first:
                first = False
                Search(j + 1, i, index, True)
            else:
                Search(j + 1, i, len(ways), False)



for i in range(t):
    root = 0
    global ways
    ways = []
    first = True
    for j in range(n[i]):
        if int(p[i][j]) == j + 1: 
            root = j + 1
            ways.append([root])
            break

    for j in range(n[i]):
        if int(p[i][j]) == root and j != root - 1:
            if first: 
                Search(j + 1, i, 0, True)
                first = False
            else:
                Search(j + 1, i, len(ways), False)
                print()

    print(len(ways))
    for j in range(len(ways)):
        print(len(ways[j]))
        for m in range(len(ways[j])):
            print(ways[j][m], end= " ")
        print()
    print()