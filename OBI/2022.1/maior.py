n = int(input()) #menor valor
m = int(input()) #maior valor
s = int(input()) #soma dos digitos
valor = -1
for i in range(n,m+1):
    soma = 0
    for j in range(len(str(i))): soma += int(str(i)[j])
    if soma == s: valor = i

print(valor)
        
