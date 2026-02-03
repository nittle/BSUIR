from random import randint

num = int(input('Input num of elmts: '))

arr = []

for _ in range(num):
    arr.append(randint(1, 100))


def bubble_sort(arr):
    ops = 0
    n = len(arr)
    isSwapped = False

    for i in range(n):
        for j in range(n - i - 1):
            if (arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
                ops += 1
                isSwapped = True

        if (not isSwapped):
            break
    return ops


ops = bubble_sort(arr)
print(arr)
print(ops)
