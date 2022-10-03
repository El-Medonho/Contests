inp = list(map(int, input().split()))
w = inp[0]
h = inp[1]
n = inp[2]

l = int((w*h*n)**(1/2))
r = int(1e19)
nl = 0
while True:
    if l>=r: print(l); break
    md = (l+r)//2
    nl = (md//w)*(md//h)
    if nl<n: l = md+1
    if nl>=n: r = md 