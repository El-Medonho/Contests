import sys

inp = input().split(" ")
n = int(inp[0])
wild = int(inp[1])

hasPassed = False

cards = []
nmg = 0

for i in range(n):
    cards.append([])
    for j in range(14):
        cards[i].append(0)
    ninp = input()
    for j in range(4):
        if ninp[j] == "A": cards[i][0] += 1
        elif ninp[j] == "D": cards[i][9] += 1
        elif ninp[j] == "Q": cards[i][10] += 1
        elif ninp[j] == "J": cards[i][11] += 1
        elif ninp[j] == "K": cards[i][12] += 1
        else: cards[i][int(ninp[j])-1] += 1

cards[wild-1][13] = 1
wn = 20
for i in range(n):
    if i != wild-1:
        for j in range(13):
            if cards[i][j] == 4 and i < wn:
                nmg = i+1
                wn = i
if nmg != 0:
    print(nmg)
    sys.exit()

def Turn(start, toraise):

    global cards
    global hasPassed




    last = start-1

    if start == n:
        start = 0
    if toraise != -1:
        cards[start][toraise] += 1  #passing the card

    # for i in range(n):
    #     for j in range(14):
    #         if cards[i][j] != 0:
    #             for k in range(cards[i][j]):
    #                 print(str(j), end = " ")
    #     print()

    # print()
    # print()


    winner = [-1,0]
    save = 0

    for j in range(13):                     #checking victory
        if cards[start][j] != 0:
            if cards[start][j] != 4:
                break
            else:
                save = j
        if j == 12 and cards[start][13] == 0:           
            winner = [start + 1, save]

    for j in range(13):
        if cards[last][j] != 0:
            if cards[last][j] != 4:
                break
            else: 
                save = j
        if j == 12 and cards[last][13] == 0:           
            if winner[0] == -1 or save < winner[1]:
                winner = [last + 1, save]

    if winner[0] != -1: return winner[0]

    if cards[start][13] == 1:
        if hasPassed:

            hasPassed = False
            cards[start][13] = 0
            return Turn(start+1, 13)
        else: hasPassed = True

    elmin = [0,0,0,0,0]
    for j in range(13):
        elmin[cards[start][j]] += 1

    discard = -1

    for j in range(4):
        if elmin[j+1] != 0:
            for k in range(13):
                if cards[start][k] == j+1: 
                    discard = k
                    break
            break
        
    cards[start][discard] -= 1
    return Turn(start + 1, discard)

print(Turn(wild-1, -1))