from audioop import reverse


t = int(input())
ans = []

for g in range(t):
    n = int(input())
    t = input()
    s = ""
    p = 0
    ref = ord("a")-1
    for i in range(n):
        if p != 0 and p <3: p+=1; continue
        if t[n-i-1] != "0": s += chr(ref+int(t[n-i-1]))
        else: p = 1; s += chr(ref+int(t[n-i-3] + t[n-i-2]))
        
    ans.append(s[::-1])

for i in ans: print(i)

