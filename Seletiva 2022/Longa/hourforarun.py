import math

inp = input().split(" ")

laps = int(inp[0])
signs = int(inp[1])
total = laps * signs
values = []
for i in range(9):
    penis = total * ((i+1)/10)
    penis = math.ceil(penis)
    values.append(penis)
for j in range(len(values)-1):
    print(values[j], end = " ")
print(values[-1]) 