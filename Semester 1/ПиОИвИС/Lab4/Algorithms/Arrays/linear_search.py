from random import randint


def linearSearch(arr, target):
    for ind, el in enumerate(arr):
        if el == target:
            return ind

    return -1


arr = [randint(0, 100) for _ in range(10)]
print(arr)
target = int(input('Input target: '))
print('Result:', linearSearch(arr, target))
