n, t = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
if t == 1:
    print(7)
elif t == 2:
    if A[0] > A[1]:
        print("Bigger")
    elif A[0] == A[1]:
        print("Equal")
    else:
        print("Smaller")
elif t == 3:
    print(sorted(A[0:3])[1])
elif t == 4:
    print(sum(A))
elif t == 5:
    print(sum([i if i % 2 == 0 else 0 for i in A]))
elif t == 6:
    print(*[chr(ord('a')+i % 26) for i in A], sep='')
elif t == 7:
    i = 0
    visited = [False for _ in A]
    while i < n-1:
        if visited[i]:
            print("Cyclic")
            break
        visited[i] = True
        i = A[i]
    if i == n-1:
        print("Done")
    elif i > n-1:
        print("Out")
