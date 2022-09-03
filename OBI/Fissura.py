inp1 = input()
k = inp1.split(" ")
n = int(k[0])
power = int(k[1])

cords = []
table = []
str = ""
for i in range(n): 
    cords.append([])
    str = input()
    for j in str:
        cords[i].append(j)
def Check(i,j):
    if cords[i][j] == "*": return 0
    if int(cords[i][j]) <= power: 
        cords[i][j] = "*"

        if (i+1) // n == 0: Check(i+1, j)
        if (i-1) // n == 0: Check(i-1, j)
        if (j+1) // n == 0: Check(i, j+1)
        if (j-1) // n == 0: Check(i, j-1) 

Check(0,0)
a = ""
for i in range(len(cords)):
    a = ""
    for j in cords[i]:
        a += j
    print(a)