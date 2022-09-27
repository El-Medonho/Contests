import math

inp = input().split(" ")
n = int(inp[0])
l = int(inp[1])
d = int(inp[2])

l = l*1000

res = math.ceil(n*d/l)
res = res * l
print(res//1000)