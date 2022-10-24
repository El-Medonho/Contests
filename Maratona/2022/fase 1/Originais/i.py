check = True
s = list(map(int,input().split()))
for i in range(8):
    if s[i] == 9: 
        print("F")
        check = False
        break
if check: print("S")
