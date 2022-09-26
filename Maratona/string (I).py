import math


k = int(input())
inp = input().split(" ")
inicio = int(inp[0])
final = int(inp[1])

numi = [0,0]
numf = [0,0]

string = []

#------------


def Search(i):

    if i <= 9: return [i,0]

    dig = 9
    s = ""
    lastdig = 9
    while dig < i:
        s = s + "9"
        lastdig = dig
        dig = dig + (int(s + "9") - int(s)) * (len(s)+1)

    digitos = len(s)+1

    dig = i - lastdig
    num = int(s) + math.ceil(dig/digitos)

    return [num, (dig % digitos) - 1]   # numero, digito do numero. exemplo: [193, 1] dizendo que começa no digito 9 de 193

numi = Search(inicio)
numf = Search(final)

best = []

for i in range(k): best.append("0")

# print(numi)

string += str(numi[0])[numi[1]:]
numnum = numi[0] + 1

# print(string)

dif = final - inicio + 100

# dif -= len(string)

while dif >= 0:
    string += str(numnum)[0:]
    numnum += 1
    dif -= len(str(numnum))

# print(len(string))

decimal = 0

for i in range(final-inicio+2-k):
    for j in range(k):
        if inicio + i + k > final: break
        try:
            # print(string[i+j])
            if string[i+j] == best[j]: continue
            if string[i+j] < best[j]: break
            if string[i+j] > best[j]: 
                for x in range(k):
                    best[x] = string[i+x]
                break
        except: break



ans = ""
for i in best:
    ans += i
print(int(ans))