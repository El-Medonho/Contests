def separate_tree(tree):
    tree = [int(x) for x in tree]
    if len(tree) == 1:
        return [[1]]
    n = len(tree)
    paths = []
    child_taken = [0] * n
    path_id = [None] * n
    for i in range(n):
        if i+1 == tree[i]:
            continue
        parent = tree[i]
        if (child_taken[parent-1] == 1):
            if (not path_id[i] is None):
                continue
            path = [i+1]
            paths.append(path)
            path_id[i] = len(paths)-1
        else:
            child_taken[parent-1] = 1
            if (not path_id[parent-1] is None) and (not path_id[i] is None):
                j = path_id[i]
                for k in paths[j]:
                    path_id[k-1] = path_id[parent-1]
                    paths[path_id[parent-1]].append(k)
                paths[j] = []
            elif not path_id[parent-1] is None:
                paths[path_id[parent-1]].append(i+1)
                path_id[i] = path_id[parent-1]
            elif not path_id[i] is None:
                paths[path_id[i]].append(parent)
                path_id[parent-1] = path_id[i]
            else:
                path = [parent, i+1]
                paths.append(path)
                path_id[i] = len(paths)-1
                path_id[parent-1] = path_id[i]
    paths = [path for path in paths if not len(path) == 0]
    return paths

t = int(input())
n = []
p = []
for i in range(t):
    n.append(int(input()))
    p.append(input().split(" "))

for i in range(t):
    paths = separate_tree(p[i])
    print(len(paths))
    for path in paths:
        print(len(path))
        print(' '.join([str(x) for x in path]))
    print()