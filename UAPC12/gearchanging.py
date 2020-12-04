n, m, p = [int(i) for i in input().split()]
c_teeth = [int(i) for i in input().split()]
w_teeth = [int(i) for i in input().split()]
ratios = [(w, c, w/c) for w in w_teeth for c in c_teeth]
ratios.sort(key=lambda i: i[2])
for i in range(1, len(ratios)):
    if (ratios[i][2]/ratios[i-1][2]-1)*100 > p:
        print("Time to change gears!")
        break
else:
    print("Ride on!")
