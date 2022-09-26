from queue import PriorityQueue
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
 
 
inp = input().split(" ")
n = int(inp[0])
m = int(inp[1])
 
flights = []
ans = []
 
for i in range(n):
    flights.append([])
 
for i in range(m):
    # inp = list(map(int, input().split()))
    a,b,c = get_ints()
    flights[(a)-1] += [(c), (b) - 1]
    # flights[int(0)-1] += [int(0), int(1) - 1]
 
 
visited = []
best = []
# best = [0]
 
for i in range(n):
    visited.append(0)
    best.append(100000000000000)
 
best[0] = 0
pq = PriorityQueue()
pq.put([0, 0])
 
while not pq.empty(): 
    current = pq.get()
 
    # if current[1] == j: 
    #     ans.append(current[0])
    #     break
 
    if visited[current[1]] == 0:

        for j in range(len(flights[current[1]])//2):
            i = j*2
            x = flights[current[1]][i]
            y = flights[current[1]][i+1]
            if visited[y] == 0 and best[y] > current[0] + x :
                pq.put([current[0] + x, y])
                best[y] = current[0] + x


#         for i in flights[current[1]]:
#             if visited[i[1]] == 0 and best[i[1]] > current[0] + i[0] :
#                 pq.put([current[0] + i[0], i[1]])
#                 best[i[1]] = current[0] + i[0]

 
#     visited[current[1]] = 1
 
 
# for i in best:
#     print(i, end = " ")
# print()

sys.stdout.write(" ".join(map(str,best)) + "\n")