n = int(input())
grid = []
boolgrid = []
for i in range(n):
    grid.append(input())
    boolgrid.append([])

    for j in range(n):
        boolgrid[i].append(0)

boolgrid[0][0] = 1


way = -1

letters = []

for i in range(10):
    letters.append(0)

def DFS(sum, chars, passed, pos):
    global way
    global grid

    char = chars.copy()
    ongoing = passed.copy()

    # ongoing[pos[0]][pos[1]] = 1

    order = [0,0]
    curcase = ord(grid[pos[0]][pos[1]])
    if curcase >= ord("a"):
            order[0] = curcase - ord("a")
            order[1] = 1
    else: order[0] = curcase - ord("A"); order[1] = 2
    char[order[0]] = order[1]           #setting chars for current letter of current position in the grid

    distance = (n-pos[0]-1)+(n-pos[1]-1)
    case = [0,0]
    if way != -1 and (sum + distance) > way: return 0
    if pos == [n-1,n-1]:
        if sum <= way or way == -1:
            way = sum
            return 0                    #checking if is on the last square or if the sum is bigger than the record
        return 0



    if pos[1] != n-1 and passed[pos[0]][pos[1]+1] == 0: #right

        newcase = ord(grid[pos[0]][pos[1]+1])
        if newcase >= ord("a"):
            case[0] = newcase - ord("a")
            case[1] = 1
        else: case[0] = newcase - ord("A"); case[1] = 2

        if char[case[0]] == 0 or char[case[0]] == case[1]:
            ongoing[pos[0]][pos[1]+1] = 1
            DFS(sum+1, char, ongoing, [pos[0], pos[1]+1])
            ongoing[pos[0]][pos[1]+1] = 0


    if pos[0] != n-1 and passed[pos[0]+1][pos[1]] == 0: #down

        newcase = ord(grid[pos[0]+1][pos[1]])           #possivelmente ta dando bosta no passed
        if newcase >= ord("a"):
            case[0] = newcase - ord("a")
            case[1] = 1
        else: case[0] = newcase - ord("A"); case[1] = 2

        if char[case[0]] == 0 or char[case[0]] == case[1]:
            ongoing[pos[0]+1][pos[1]] = 1
            DFS(sum+1, char, ongoing, [pos[0]+1, pos[1]])
            ongoing[pos[0]+1][pos[1]] = 0

    if pos[1] != 0 and passed[pos[0]][pos[1]-1] == 0: #left

        newcase = ord(grid[pos[0]][pos[1]-1])
        if newcase >= ord("a"):
            case[0] = newcase - ord("a")
            case[1] = 1
        else: case[0] = newcase - ord("A"); case[1] = 2

        if char[case[0]] == 0 or char[case[0]] == case[1]:
            ongoing[pos[0]][pos[1]-1] = 1
            DFS(sum+1, char, ongoing, [pos[0], pos[1]-1])
            ongoing[pos[0]][pos[1]-1] = 0

    if pos[0] != 0 and passed[pos[0]-1][pos[1]] == 0: #up

        newcase = ord(grid[pos[0]-1][pos[1]])
        if newcase >= ord("a"):
            case[0] = newcase - ord("a")
            case[1] = 1
        else: case[0] = newcase - ord("A"); case[1] = 2

        if char[case[0]] == 0 or char[case[0]] == case[1]:
            ongoing[pos[0]-1][pos[1]] = 1
            DFS(sum+1, char, ongoing, [pos[0]-1, pos[1]])
            ongoing[pos[0]-1][pos[1]] = 0

    return 0


DFS(1, letters, boolgrid, [0,0])

print(way)