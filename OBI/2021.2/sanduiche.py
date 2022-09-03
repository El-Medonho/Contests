inp = input().split(" ")
ingr = int(inp[0])
urgh = int(inp[1])

general = set([])
excep = []
for i in range(ingr):
    excep.append(set([]))

for i in range(ingr): general.add(i+1); excep[i].add(i+1)

for i in range(urgh):
    inp = input().split(" ")
    temp1 = int(inp[0])
    temp2 = int(inp[1])
    excep[temp1-1].add(temp2)
    excep[temp2-1].add(temp1)

sum = -1
primeiro = 1
def Search(blacklist):
    global sum
    sum += 1
    if blacklist == general: return 0
    for j in (general.difference(blacklist)):
        blacklist.add(j)
        Search(blacklist.union(excep[j-1]))
        


Search(set([]))
print(sum)