n = int(input())
lista = input().split(" ")

def Search(i, n):
    if lista[i] == "1": return n+1
    else:
        newi = int(lista[i]) - 2
        return Search(newi, n+1)
print(str(Search(-1,0))) 