inp = list(map(int, input().split()))
exp = inp[0]
xn = 2**exp
ans = 0
target = [xn//2,xn//2]
cur = [inp[1],inp[2]]
mid = xn//2
while cur != target:
    for i in range(2):
        if cur[i] <= target[i]:
            cur[i]*=2
        else: cur[i] = (cur[i]*2)-xn
    ans+=1
print(ans)