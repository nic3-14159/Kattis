nums = list()
lr = [1, 0, 1, 2, 0, 1, 2, 0, 1, 2]
for i in range(1, 201):
    h = i//100
    t = (i//10) % 10
    o = (i % 100) % 10
    if i < 10:
        nums.append(i)
    elif i < 100:
        if (t <= o and lr[t] <= lr[o]) or (o == 0 and lr[t] < 2):
            nums.append(i)
    elif lr[h] <= lr[t] and lr[t] <= lr[o]:
        if (h <= t <= o) or o == 0:
            nums.append(i)

n = int(input())
for _ in range(n):
    time = int(input())
    left = 0
    right = len(nums)-1
    while left <= right:
        mid = (left + right)//2
        if nums[mid] == time:
            break
        if time < nums[mid]:
            right = mid-1
        else:
            left = mid+1
    if mid != 0 and abs(time-nums[mid-1]) < abs(time-nums[mid]):
        mid -= 1
    if mid != len(nums)-1 and abs(time-nums[mid+1]) < abs(time-nums[mid]):
        mid += 1
    print(nums[mid])
