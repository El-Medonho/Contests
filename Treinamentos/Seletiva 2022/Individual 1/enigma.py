cripto = input()
key = input()

def Check(i):
    for j in range(len(key)):
        if key[j] == cripto[i+j]: return 0
    return 1

sum = 0


if len(cripto)>=len(key):
    for i in range(len(cripto)-len(key)+1):
        sum+=Check(i)

print(sum)
