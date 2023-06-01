n = int(input())

inp = input().split(" ")
arr = inp

for i in range(len(arr)):
    arr[i] = float(arr[i])

dp = []

for i in range(n+1):
    dp.append([])
    for j in range(n+1):
        dp[i].append(0)

dp[0][0] = 1

for i in range(n):
    ii = i+1
    for j in range(ii+1):
        if(j != 0): dp[ii-j][j] += dp[ii-j][j-1] * (1-arr[ii-1])
        if(j != ii): dp[ii-j][j] += dp[ii-j-1][j] * (arr[ii-1])

ans = 0
for i in range(n+1):
    if(i <= n//2): continue
    ans += dp[i][n-i]

print(ans)
