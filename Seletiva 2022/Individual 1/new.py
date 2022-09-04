n = int(input())
wall = input().split(" ")

for i in range(wall):
    wall[i] = int(wall[i])

#-----------------

def Run(start, size):
    sum = 0
    for i in range(size):
        if i >= size:
            if 

    return 0

def Check(start, best):
    for i in range(wall[start]):
        if Run(start) == 0: 
            if start == len(wall): return best
            else: Check(start+1, best)