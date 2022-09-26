s = int(input())
quad = input().split(" ")
nlog = input().split(" ")

for i in range(s):
    quad[i] = int(quad[i])
    nlog[i] = int(nlog[i])

quad.sort()
nlog.sort()
i = 0
j = 0
sum = 0

while i < s and j < s:
    if quad[i] < nlog[j]:
        i += 1
        j += 1
        sum += 1
    else: j += 1

print(sum)