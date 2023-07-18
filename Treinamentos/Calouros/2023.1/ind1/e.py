t = int(input())
resp = []

while(t):
    t-=1
    n = int(input())
    x = "Bob"
    if(n >= 5): x = "Alice"
    resp.append(x)
    
for i in resp: print(i)