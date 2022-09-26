#inputs --------------

result = []

while True:
    try:
        n = int(input())

        inp = input().split(" ")
        innit = [int(inp[0]), int(inp[1])]

        a = [[],[]]
        time = [[],[]]

        inp = input().split(" ")
        for i in range(n):
            a[0].append(int(inp[i]))
            time[0].append(0)

        inp = input().split(" ")
        for i in range(n):
            a[1].append(int(inp[i]))
            time[1].append(0)
        t = [[],[]]


        if n > 1:
            inp = input().split(" ")
            for i in range(n-1):
                t[0].append(int(inp[i]))

        if n > 1:
            inp = input().split(" ")
            for i in range(n-1):
                t[1].append(int(inp[i]))

        inp = input().split(" ")
        out = [int(inp[0]), int(inp[1])]

        #inputs end here ---------------

        time[0][0] = innit[0] + a[0][0]
        time[1][0] = innit[1] + a[1][0]

        for i in range(n-1):
            for j in range(2):
                u = (j+1)%2
                time[j][i+1] = min(time[j][i] + a[j][i+1], time[u][i] + t[u][i] + a[j][i+1])

        
        result.append(min(time[0][n-1] + out[0], time[1][n-1] + out[1]))

        
    
    except: 

        for i in range(len(result)):
            print(result[i])
        break