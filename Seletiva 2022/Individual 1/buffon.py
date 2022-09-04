n = int(input())


votes = []

for i in range(n):
    votes.append(int(input()))

carlos = votes[0]

def Check():
    for i in range(n-1):
        if votes[i+1] > carlos: return "N"
    return "S"

print(Check())