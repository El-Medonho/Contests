s = int(input())
a = int(input())
b = int(input())

for i in range(b-a):
    k = a
    sum = 0
    while(k!=0):
        sum += k%10
        k = k//10
    if sum == s: break
    a += 1

print(a)

for i in range(b-a):
    k = b
    sum = 0
    while(k!=0):
        sum += k%10
        k = k//10
    if sum == s: break
    b -= 1

print(b)