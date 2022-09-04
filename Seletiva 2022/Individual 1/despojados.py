n = int(input())

primos = []

first = True
one = n
sum = 0
change = True

def CheckPrime(i, m):
    index = 0
    if i <= 1: return 0
    for j in range(m-1):
        if i%(j+1) == 0: index += 1
        if index > 1: return 0
    return 1

divisores = []

def Magic(i):
    return int(i//(i**(1/2))) + 1

pen = 0
def Check(i,m):
    global sum
    global one
    global change
    index = 0
    if i <= 1: return 0
    for j in range(m-1):
        if i%(j+1) == 0: index += 1
        if index > 1: return 0
    if n%i == 0:
        sum += 1
        while(one%i == 0):
            one = one//i
        change = False
    return 0



for i in range(n):
    if change: 
        if CheckPrime(one, Magic(one)) == 0:
            change = True
        else:
            break
    if i <= 1: continue
    if i> one: break
    m = Magic(i)
    Check(i,m)

penis = int(2**(sum))-sum-1

if n == 1 or n == 2 or n == 3 or n == 4 or n == 5: print(0)

else: print(penis)