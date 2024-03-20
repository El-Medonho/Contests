t = int(input())

resp = []

while(t):
    t-=1

    n = int(input())

    s = input()

    base = 0

    ans = 0

    h = int(s)

    for i in range(len(s)):
        ans += h
        h //= 10

    resp += [ans]

for i in resp: print(i)