t = int(input())
resposta = []

for gg in range(t):
    base = "codeforces"
    s = input()
    cnt = 0
    
    for i in range(10):
        if(s[i] != base[i]): cnt += 1

    # print(cnt)
    resposta.append(cnt)

for i in range(t): print(resposta[i])