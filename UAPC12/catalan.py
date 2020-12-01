catalan = [1]
n = int(input())
for _ in range(n):
    q = int(input())
    if q > len(catalan)-1:
        for i in range(len(catalan)-1, q):
            catalan.append(2*catalan[i]*(2*i+1)//(i+2))
    print(catalan[q])
