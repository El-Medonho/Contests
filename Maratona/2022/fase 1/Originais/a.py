n = int(input())
string = input()
reset = True
reoccur = 0
ans = 0
for i in range(n):
    if string[i] == "b":
        reset = True
        reoccur = 0
    if string[i] == "a":
        if reoccur > 1: ans+=1
        elif reoccur == 1:
            ans += 2
            reoccur += 1
        else: reoccur += 1 
print(ans)
