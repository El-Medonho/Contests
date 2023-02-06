t = int(input())
n = []
p = []
for i in range(t):
    n.append(int(input()))
    p.append(input().split(" "))
    
def BinaryInput(l,x):
    right = len(l)
    left = 0
    mid = 0
    if len(l) == 0: return l + [x]
    while(True):
        mid = (left + right) // 2
        if left >= right: 
            if mid == len(l): l.append(x)
            else: l[mid:mid] = [x]
            return l
        elif l[mid] >= x: right = mid
        else: left = mid + 1

def BinarySearch(l,x):
    index = -1
    right = len(l) - 1
    left = 0
    mid = 0
    while(True):
        mid = (left + right) // 2
        if left > right: break
        if l[mid] > x: right = mid - 1
        elif l[mid] < x: left = mid + 1
        else: index = mid; break
    return index

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
                if BinarySearch(blacklist, CurrentStop) == -1:
                    blacklist = BinaryInput(blacklist, CurrentStop)
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





