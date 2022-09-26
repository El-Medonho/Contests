from queue import PriorityQueue

p = PriorityQueue()
a = [1,2,3]

p.put(a[0])
p.put(a[1])

print(p)

a[0] = 100

print(p.get(), p)