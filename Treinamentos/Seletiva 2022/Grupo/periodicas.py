inp = input().split(" ")
n = int(inp[0])
limit = int(inp[1])

inp = input().split(" ")
num = []
num.append(int(inp[0]))
num.append(int(inp[1]))

primes = []

ind = 0
for i in range(int(max(num[0],num[1]) ** (1/2))):
    k = i+2
    
    while num[0] % k == 0 or num[1] % k == 0:
        
        if num[0] % k == 0: num[0] = num[0] // k
        if num[1] % k == 0: num[1] = num[1] // k
        primes.append(k)
    for j in range(2):
        if k > int(num[j] ** (1/2)):
            ind += 1
            if num[j] != 1: 
                primes.append(num[j])
                num[j] = 1
    if ind == 2: break

primes.sort()
mmc = 1

for b in primes:
    mmc *= b


# def Search(num, left, right):

if n > 2:
    for a in range(n-2):
        current = int(inp[a+2])
        penis = 0
        indice = 0
        for i in range(int(current ** (1/2)) + 1):
            k = i+2
            
            while current % k == 0:
                current = current // k

                if primes[indice] > k:
                    primes.append(k)
                    mmc *= k
                else: 
                    if indice + 1 <= len(primes) - 1: indice += 1

                

            if k > int(current ** (1/2)):
                if current != 1: primes.append(current)
                break
            while primes[indice] <= k: 
                if indice + 1 <= len(primes) - 1: indice += 1

mmc2 = mmc
mmc3 = [mmc, limit]

for a in range(limit):
    current = (limit) - a
    if current <= 1: break
    abda = current
    indice = 0
    for i in range(int(current ** (1/2)) + 1):
            k = i+2
            
            while current % k == 0 or num[1] % k == 0:
                current = current // k

                if primes[indice] > k:
                    primes.append(k)
                    mmc2 *= k
                else: 
                    if indice + 1 <= len(primes) - 1: indice += 1

                

            if k > int(current ** (1/2)):
                if current != 1: mmc2 *= current
                if mmc2 > limit: break
                if mmc2 > mmc3[0]: 
                    mmc3[0] = mmc2
                    mmc3[1] = abda
                break
            while primes[indice] <= k: 
                if indice + 1 <= len(primes) - 1: indice += 1

print(mmc3[1])
