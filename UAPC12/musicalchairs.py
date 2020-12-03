n = int(input())
profs = [(i+1, int(opus)) for i, opus in enumerate(input().split())]
pos = 0
while len(profs) != 1:
    pos = (pos+profs[pos][1] - 1) % len(profs)
    profs.pop(pos)
    pos = pos % len(profs)
    
print(profs[0][0])
