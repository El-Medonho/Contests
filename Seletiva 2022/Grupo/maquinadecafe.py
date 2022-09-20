n = [0,0,0]
n[0] = int(input())
n[1] = int(input())
n[2] = int(input())

sum = [0,0,0]

for i in range(3):
    for j in range(3):
        sum[i] += n[j] * abs(i-j)

print(min(sum[0], sum[1], sum[2]) * 2)
