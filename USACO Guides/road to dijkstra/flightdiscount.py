from queue import PriorityQueue
import sys
 
sys.setrecursionlimit(1000000)
 
inp = input().split(" ")
n = int(inp[0])
m = int(inp[1])
 
visited = []    #cities that have already been visited have a 1
best = [] 
flights = []    #{1:[[2,3],[3,8]]}  [destination, cost]
ended = False   #tells if SearchInteiro has reached n
qinteiros = PriorityQueue()
qmetade = PriorityQueue()
 
qinteiros.put((0, 1))
 
for i in range(n): 
    visited.append([0,0]);
    best.append([10**11, 10**11])
    flights.append([])

best[0][0] = 0
 
for i in range(m):
    inp = input().split(" ")
    flights[int(inp[0])-1].append([int(inp[1]), int(inp[2])])
 
def SearchMetade():
    global qinteiros
    global qmetade
    global flights
    global visited
    global ended
 
    current = qmetade.get()
    # print(current[0], current[1])
 
    if current[1] == n:
        print(best[n-1][1])
        sys.exit()  
        return current[1] 
 
 
    visited[current[1] - 1][1] = 1
 
    for i in flights[current[1]-1]:
        if best[current[1]-1][1] + i[1] < best[i[0]-1][1]: best[i[0]-1][1] = best[current[1]-1][1] + i[1]
        if visited[i[0] - 1][1] == 0:
            qmetade.put([best[i[0]-1][1], i[0]]) 
            visited[i[0]-1][1] = 1
 
    if ended: 
        while True: SearchMetade()
 
    return 0
 
def SearchInteiro():
    global qinteiros
    global qmetade
    global flights
    global visited
    global ended
 
    if qinteiros.empty(): return 0
 
    current = qinteiros.get()
 
    if current[1] == n:     #em um dos exemplos chega aqui em 0.67s, o resto nem isso, acho q o meu djikstra está errado
        ended = True
 
    visited[current[1] - 1][0] = 1
 
    for i in flights[current[1]-1]:
        if best[current[1]-1][0] + i[1] < best[i[0]-1][0]: best[i[0]-1][0] = best[current[1]-1][0] + i[1]
        if best[current[1]-1][0] + (i[1]//2) < best[i[0]-1][1]: best[i[0]-1][1] = best[current[1]-1][0] + (i[1]//2)
        if visited[i[0] - 1][0] == 0:
            qinteiros.put([best[i[0]-1][0], i[0]])
            visited[i[0]-1][0] = 1
        if visited[i[0] - 1][1] == 0:
            qmetade.put([best[i[0]-1][1], i[0]])
            visited[i[0]-1][1] = 1
 
 
    SearchInteiro()
 
    return 0
 
 
SearchInteiro()
print("test")
sys.exit()
SearchMetade()