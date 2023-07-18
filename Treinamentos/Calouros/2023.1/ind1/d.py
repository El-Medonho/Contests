[x,y] = input().split(' ')
x = int(x)
y = int(y)

# if(y % 2 == 0 and y >= 2*x and y<= 4*x):
#     print("Yes")

# else: print("No")

soma = 0
if(y % 2 == 1):
    print("No")
    exit()

soma = 2*x

while(soma <= 4*x):
    if(soma == y):
        print("Yes")
        exit()
    
    soma += 2

print("No")