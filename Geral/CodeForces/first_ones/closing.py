a = input().split(" ")
n = int(a[0])
m = int(a[1])
ways = []
queue = []
vis = [True]*n
closed = []
ans = ["NO"]*n

for i in range(n):
    ways.append([])

for i in range(m):
    a = input().split(" ")
    ways[int(a[0]) - 1].append(int(a[1]))   #farm 1 is ways[0]
    ways[int(a[1]) - 1].append(int(a[0]))
    print(ways)

def Check():
    for i in queue:
        queue.pop(0)
        for j in ways[i]:
            if vis[j-1] == True:
                vis[j-1] = False
                queue.append(j-1)
    for i in vis:
        if i == True: return False
    return True

def isConnected():
    for i in range(n):
        if vis[i] == True:
            queue.append(i)
            vis[i] = False
            return Check()

for i in range(n-1):
    verd = isConnected()
    if verd: ans[i] = "YES"
    closed.append(int(input()))
    vis = [True]*n
    for j in closed: vis[j-1] = False

ans[-1] = "YES"
c = input()


print(ans)