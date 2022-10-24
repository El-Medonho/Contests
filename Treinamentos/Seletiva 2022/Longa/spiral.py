import sys
import math

inp = input().split(" ")
size = int(inp[0])
beans = int(inp[1])

if beans <= size: print("1 " + str(beans)); sys.exit()

beans -= size

#second degree equation

a = 1
b = -1
c = beans-(size*(size-1))

delta = (b**2)-4*a*c
ans = (-b+(delta**(1/2)))/(2*a)



close = math.ceil(ans)

spent = ((size-1) + (close)) * ((size) - close)

left = beans - spent



# print(ans, math.ceil(ans))
# print(beans - spent)

position = [0,0]
factor = (close + ((size-close)//2))

# print(factor)

if(size % 2 == close % 2):
    position = [1+(size-factor), factor]
    if left > (close-1):
        left -= (close-1)
        position[1] -=  left
        position[0] += close-1
    else:
        position[0] += left

else:
    position = [1+factor, (size-factor)]
    if left > (close-1):
        left -= (close-1)
        position[1] +=  left
        position[0] -= close-1
    else:
        position[0] -= left

print(str(position[0]) + " " + str(position[1]))
