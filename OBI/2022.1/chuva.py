n = int(input())
s = int(input())
medidas = input().split(" ")


intervalos = 0

for i in range(len(medidas)):
    sum = 0
    j = i
    while(sum <= s) and (j < len(medidas)):
        sum += int(medidas[j])
        j += 1
        if sum == s: intervalos += 1
print(intervalos)

