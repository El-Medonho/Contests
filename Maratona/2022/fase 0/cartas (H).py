test = int(input())
res = []

for i in range(test):
    cards = int(input())

    a = 3
    b = 7
    c = (-2 * cards) + 4

    bask = (-b + ((b**2 - 4 * a *c) ** (1/2)))/(2 * a)

    res.append(int(bask) + 1)

for i in range(test):
    print(res[i])