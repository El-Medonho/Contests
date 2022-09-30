t = int(input())
ans = []
for i in range(t):
    inp = input().split(" ")
    a = int(inp[0])
    b = int(inp[1])
    c = int(inp[2])

    c1 = a-1
    c2 = abs(c-b)+c-1

    if c1 == c2: ans.append(3)
    elif c1 < c2: ans.append(1)
    else: ans.append(2)

for i in ans:
    print(i)