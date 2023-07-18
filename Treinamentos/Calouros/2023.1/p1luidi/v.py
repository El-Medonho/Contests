x = [4,3,2,1,1]
m = 3

kk = 0

k = -174275275373783
l = 85416841646846

v=[]

while m > 0:
    p = kk

    for i in x:
        if(i == k):
            if( p <= 0):
                l = i
            p = p - 1
        elif( i > k and i < l):
            l=i

    if (l==k):
        kk = kk + 1
    else:
        kk = 1

    v.append(l)
    k = l
    l = 1e30
    m = m - 1

print(v)


#percorrer o vetor todo
#ver se i é menor que i+1