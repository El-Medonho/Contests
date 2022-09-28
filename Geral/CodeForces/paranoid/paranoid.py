t = int(input())
n = []
s = []
sum = 0
for i in range(t):
    n.append(int(input()))
    s.append(input())

def Check_complex(key, value):
    global sum
    if key[0] != 0:
        u = keys[sv[key[0] - 1] + str(value)]
        if u != "none" and paranoid.get((key[0] - 1, key[1])) == None:
            paranoid[(key[0] - 1, key[1])] = u
            sum += 1
            Check_complex((key[0] - 1, key[1]), u)
    if key[1] != len(sv) - 1:
        u = keys[str(value) + sv[key[1] + 1]]
        if u != "none" and paranoid.get((key[0], key[1] + 1)) == None:
            paranoid[(key[0], key[1] + 1)] = u
            sum += 1
            Check_complex((key[0], key[1] + 1), u)
    for l in range(key[0] - 1):  #substring [x, r-1] + [r, y]
        if paranoid.get((l, key[0] - 1)) != None:
            u = keys[str(paranoid[l, key[0] - 1]) + str(value)]
            if u != "none" and paranoid.get((l, key[1])) == None:
                paranoid[(l, key[1])] = u
                sum += 1
                Check_complex((l, key[1]), u)

def Check_simple(i):
    global sum
    u = keys[sv[i] + sv[i+1]]
    if u != "none":
        paranoid[(i,i+1)] = u
        sum += 1
        Check_complex([i,i+1], u)


    return 0
for i in range(t):
    sv = list(s[i])
    sum = n[i]
    keys = {"01": "1", "10" : 0, "11" : "none", "00" : "none" }
    paranoid = {} #keys is (l,r), output is value of paranoid string ex: 0 or 1

    for i in range(len(sv)-1):
        Check_simple(i)
    print(sum)