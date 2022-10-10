import sys
inp = list(map(int, input().split()))

n = inp[0]
x = inp[1]
y = inp[2]
curr = [x,y]
target = [2**(n-1),2**(n-1)]
bound = 2**n
mid = 2**(n-1)
ans = 0

while curr != target:
    for i in range(2):
        if curr[i] > mid: curr[i] = (curr[i]*2)-bound
        else: curr[i]*=2
    ans+=1

sys.stdout.write(str(ans) + "\n")
