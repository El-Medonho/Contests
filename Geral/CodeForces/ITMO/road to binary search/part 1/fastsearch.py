n = int(input())
array = [-1e10]
array += list(map(int, input().split()))
array.append(1e10)
array.sort()
k = int(input())
querry = []
for i in range(k):
    querry.append(list(map(int, input().split())))

def binaryleft(v):
    global array
    global n
    l = 0
    r = n+1
    while True:
        if l+1>=r: return l
        md = (l+r)//2
        if array[md] < v: l = md
        else: r = md

def binaryright(v):
    global array
    global n
    l = 0
    r = n+1
    while True:
        if l+1>=r: return r
        md = (l+r)//2
        if array[md] <= v: l = md
        else: r = md

for i in querry:
    a = binaryleft(i[0])
    b = binaryright(i[1])
    print(b-a-1, end = " ")

print()