import sys

inp = input().split(" ")
n = int(inp[0])
limit = int(inp[1])

inp = input().split()
numbers = []

for i in range(len(inp)):
    numbers.append(int(inp[i]))

num1 = 1
num2 = 1
mmc = numbers[0]
mdc = 0


for i in range(n-1):
    num1 = mmc
    num2 = numbers[i+1]

    while num1 % num2 != 0 and num2 % num1 != 0:
        c = num1 % num2
        num1 = num2
        num2 = c
    
    mmc = mmc * numbers[i+1] // min(num1, num2)

#----  | last step by finding the number       
#      V                                      

# ans = (limit//mmc) * mmc


# for i in range(limit):
#     k = i+1
#     num1 = mmc
#     num2 = k
#     save = 0

#     while num1 % num2 != 0:
#             c = num1 % num2
#             num1 = num2
#             num2 = c
        
#     save = mmc * k // min(num1, num2)

#     if save == ans: 
#         print(k)
#         sys.exit()

#--------- by calculating the number

save = limit//mmc
num1 = mmc  #8
num2 = save #4
factor = 1
res = 0

while min(num1,num2) != 1:
    num1 = mmc//factor
    num2 = save
    while num1 % num2 != 0 and num2 % num1 != 0:
        c = num1 % num2
        num1 = num2
        num2 = c
    factor = factor * min(num1,num2)

res = save * factor

print(res)
