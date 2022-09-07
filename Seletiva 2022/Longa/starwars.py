words = []
# while True:
#   try:
#     words.append(input().lower())
#   except EOFError:
#     break

words.append(input().lower())

tamanho = 0



for i in range(len(words)):
    tamanho = len(words[i])
    sum = 1
    letras = []
    for j in range(26):
        letras.append(0)
    for j in range(tamanho):
        sum *= (j+1)
        letras[ord(words[i][j])-ord("a")] += 1
    for j in letras:
        if j != 0:
            for k in range(j):
                sum = sum//(k+1)

    print(sum%1000000007)