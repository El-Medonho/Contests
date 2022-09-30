inp = input().split(" ")
n = int(inp[0])
k = int(inp[1])

array = list(map(int, input().split()))
query = list(map(int, input().split()))

def binarysearch(v):
    global array
    l = 0
    r = len(array)-1
    while True:
        if r < l: return -1
        md = (l+r)//2
        if v == array[md]: return md
        elif v < array[md]: r = md-1
        else: l = md+1

ans = []
for i in query:
    x = binarysearch(i)
    if x == -1: print("NO")
    else: print("YES")

