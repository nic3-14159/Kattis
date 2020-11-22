words = dict()
while True:
    entry = input()
    if entry == "":
        break
    english, foreign = entry.split()
    words[foreign] = english

try:
    while True:
        word = input()
        print(words[word] if word in words.keys() else "eh")
except EOFError:
    pass
