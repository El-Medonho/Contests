d = int(input()) #diaria padrao
a = int(input()) #adicao
n = int(input()) #dia da entrada

total = 0
if n >= 16: total = (32-n)*(d + (14*a))

else: total = (32-n)*(d + ((n-1)*a))

print(total)
