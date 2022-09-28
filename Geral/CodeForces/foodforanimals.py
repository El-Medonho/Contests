t = int(input()) #test cases
a = 0 #dogs food
b = 0 #cats food
c = 0 #universal food
x = 0 #num of dogs
y = 0 #num of cats
k = []

for i in range(t):
    k.append([])
    k[i] = input().split(" ")

for i in range(t):
    a = int(k[i][0])
    b = int(k[i][1])
    c = int(k[i][2])
    x = int(k[i][3])
    y = int(k[i][4])

    has_food = True
    x = a - x
    y = b - y
    if x < 0:
        x = abs(x)
        c -= x
        if c < 0: has_food = False
    if y < 0:
        y = abs(y)
        c -= y
        if c < 0: has_food = False

    if has_food:
        print("YES")
    else: 
        print("NO")
