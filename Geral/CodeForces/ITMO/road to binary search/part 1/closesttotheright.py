inp = list(map(int, input().split()))
n = inp[0]
k = inp[1]
array = [0]
array += list(map(int,input().split()))
querry = list(map(int, input().split()))
array.append(1e10)



for v in querry:
    l = 0
    r = len(array)-1
    while True:
        if l + 1 >= r: print(r); break
        md = (l+r)//2
        if array[md] >= v: r = md 
        elif array[md] < v: l = md