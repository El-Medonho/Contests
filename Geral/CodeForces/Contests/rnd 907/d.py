t = int(input())
resp = []

while(t):
    t-=1
    inp = input().split(" ")
    l = int(inp[0])
    r = int(inp[1])

    ans = 0
    md = 1000000007

    for i in range(65):
        h = 1 << i
        if(h * 2 <= l or h > r): continue

        nh = 1
        nnh = 1

        for j in range(65):
            nh = nnh
            nnh *= i
            if(nh < l/i or nh * i <= l or nh < h/i or nh * i <= h): continue
            if(nh > r or nh >= h * 2): break
            ans = (ans + (j) * ( (min(r, nh*i-1, h*2-1) - max(nh, l, h) + 1) % md ) ) % md

    resp.append(ans)

for i in resp: print(i)