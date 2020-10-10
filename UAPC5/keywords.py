n = int(input())
words = list()
for _ in range(0, n):
    words.append(input().lower().translate({45: 32}))

words = sorted(words)
currWord = words[0]
count = 1
for word in words:
    if word != currWord:
        count += 1
        currWord = word

print(count)
