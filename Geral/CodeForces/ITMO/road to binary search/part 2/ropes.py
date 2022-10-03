inp = list(map(int,input().split()))
n = inp[0]
k = inp[1]
ropes = []
for i in range(n):
    ropes.append(int(input()))
l = 0
r = 1e7

def Check(v):
    global ropes
    sum = 0
    for i in ropes:
        sum+=i//v
    return sum

for i in range(100):
    md = (l+r)/2
    u = Check(md)
    if u>=k: l = md
    else: r = md
print(l)