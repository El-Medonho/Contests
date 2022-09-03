n = int(input())
cadeia = input()
sum = 1

def Check(x,y):

    for i in range((y-x+1)):
        if cadeia[x+i] != cadeia[y-i]: return 0
    return (y-x+1)


for i in range(n):
    for j in range(n-i):
        if cadeia[i] == cadeia[i+j]:
            sum = max(sum,Check(i,i+j))

print(sum)