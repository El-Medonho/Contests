def is_subsequence(SA, SB):
    m = len(SA)
    n = len(SB)

    dp = [[False] * (n+1) for _ in range(m+1)]

    for i in range(m+1):
        dp[i][0] = True

    for i in range(1, m+1):
        for j in range(1, n+1):
            if SA[i-1] == SB[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[m][n]


A, B = 5, 3
SA = [1, 2, 3, 4, 5]
SB = [2, 3, 5]

list = input().split(" ")
A = int(list[0])
B = int(list[1])

SA = input().split(" ")
for i in range(len(SA)): SA[i] = int(SA[i])

SB = input().split(" ")
for i in range(len(SB)): SB[i] = int(SB[i])

if is_subsequence(SA, SB):
    print('S')
else:
    print('N')