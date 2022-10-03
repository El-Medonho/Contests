inp = list(map(int, input().split()))
n = inp[0]
x = inp[1]
y = inp[2]

l = 0
r = 1e10
md = 0
def check(v):
    global x,y
    sum = 0
    if v//min(x,y) >= 1:
        sum = 1
        v-=min(x,y)
        sum += v//x
        sum+= v//y
    return sum


while True:
    if l>=r: print(int(r)); break
    md = (l+r)//2
    v = check(md)
    if v<n: l = md+1
    elif v>=n: r =md