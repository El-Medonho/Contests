t = int(input())
outs = []

for g in range(t):
    equiv = []
    for k in range(51):
        equiv.append(0)
    n = int(input())
    a = []
    a = list(map(int, input().split()))
    s = input()
    news = list(s)
    ans = []
    for i in range(n):
        u = a[i]
        if equiv[u] == 0:
            equiv[u] = s[i]
            ans.append(s[i])
        else: ans.append(equiv[u])
    if ans == news: outs.append("YES")
    else: outs.append("NO")

for i in outs: print(i)