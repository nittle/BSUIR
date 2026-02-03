from random import randint

num = int(input('Input num of elmts: '))

arr = []

for _ in range(num):
    arr.append(randint(1, 20))


def counting(arr):
    count = [0] * (max(arr)+1)

    for num in arr:
        count[num] += 1

    print(arr)
    for num, freq in enumerate(count):
        arr.extend([num]*freq)


counting(arr)
print(arr)
