from random import randint


def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


arr = sorted([randint(0, 100) for _ in range(30)])

print('[', end='')
for ind, el in enumerate(arr):
    print(f'{ind}:{el}', end=' ')
print(']')

target = int(input('Input target: '))
print('Result:', binary_search(arr, target))
