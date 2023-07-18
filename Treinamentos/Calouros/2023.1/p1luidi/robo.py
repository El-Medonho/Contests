# grid de tamanho NxM
# n = int(input())
# m = int(input())

grid = eval(input())

# [[0,0,0,1], [0,1,0,0], [1,1,0,0]]

n = len(grid)
m = len(grid[0])


# (x,y) -> (x+1,y)
# (x,y) -> (x,y+1)

ans = []

def pos(x, y):
    if(x == n-1 and y == m-1):
        ans.append([x,y])
        return True

    if(x + 1 < n and grid[x+1][y] == 0):
        if (pos(x+1,y)): 
            ans.append([x,y])
            return True
    if(y + 1 < m and grid[x][y+1] == 0):
        if (pos(x,y+1)): 
            ans.append([x,y])
            return True

    return False

if(not pos(0,0)):
    print(-1)

else:
    ans.reverse()
    ans2 = []
    for i in ans:
        ans2.append(tuple(i))
    print(ans2)

# 

print()

# [[0,0], [0,1], [1,1]]
inp = eval(input())

def check():
    for i in range(len(inp)-1):     # ii é o cara da frente, e o i eh o cara anterior
        ii = i+1
        difx = inp[ii][0] - inp[i][0]
        dify = inp[ii][1] - inp[i][1]
        if( (difx == 0 and dify == 0) or (difx != 0 and dify != 0) ): return False                    # (0,0) -> (1,1) or (0,0) -> (0,0)
        if( difx > 1 or difx < 0 or dify > 1 or dify < 0 ): return False                              # (0,0) -> (2,0) or (1,0) -> (0,0)
        if( inp[i][0] >= n or inp[i][0] < 0 or inp[i][1] >= m or inp[i][1] < 0 ): return False        # suponha n = 3 e m = 3, (2,2) -> (3,2) 
        if( inp[ii][0] >= n or inp[ii][0] < 0 or inp[ii][1] >= m or inp[ii][1] < 0 ): return False    # [[0,0], [0,1], [1,1]] 

    for i in inp:   #checando se todos os caras do grid são 0
        x = i[0]
        y = i[1]
        if( grid[x][y] == 1 ): return False

    if( inp[0][0] != 0 or inp[0][1] != 0 ): return False    # checando se o primeiro cara da lista é o início do grid
    if( inp[-1][0] != n-1 or inp[-1][1] != m-1 ): return False  # checando se o ultimo cara da lista é o final do grid

    return True

print(check())

# 0 0 0 1
# 0 1 0 0
# 1 1 0 0

# (0,0) -> (1,0) -> (1,1)

# [[0,0],[0,1],[0,2],[1,2],[2,2],[2,3]]
# [[0,0],[1,0],[2,0],[2,1],[2,2],[2,3]]
# [[0,0],[0,1],[0,2],[1,2],[2,2],[2,5]]