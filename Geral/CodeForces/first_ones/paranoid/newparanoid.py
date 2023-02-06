t = int(input())
n = []
s = []
sum = 0
for i in range(t):
    n.append(int(input()))
    s.append(input())

for i in range(t):
    sum = n[i]
    lastone = s[i][0]
    for j in range(n[i]):
        u = s[i][j]
        if u != lastone:
            sum += j
        lastone = u
    print(sum)