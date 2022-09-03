inp = input().split(" ")
n = int(inp[0])
m = int(inp[1])
nums = []
for i in range(n):
    nums.append(i+1)

def adjust(i):
    if nums[n-i-1] == m-i: 
        if i != n-1: adjust(i+1)
    else:
        nums[n-i-1] +=1
        for j in range(i):
            nums[n-i+j] = nums[n-i+j-1] + 1
while(True):
    for i in range(len(nums)):
        print(nums[i], end = " ")
    print()
    old = nums.copy()
    adjust(0)
    if old == nums: break
    