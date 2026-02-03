# Find the minimal element in the array
# Move it to the front of the unsorted part
# Do it as many times as there re elmts in the array

from random import randint

num = int(input('Input num of elmts: '))

arr = []

for _ in range(num):
    arr.append(randint(1, 100))


def selection_sort(arr):
    ops = 0
    n = len(arr)

    for i in range(n - 1):
        min_ind = i
        for j in range(i+1, n):
            if arr[j] < arr[min_ind]:
                min_ind = j

        arr[min_ind], arr[i] = arr[i], arr[min_ind]
        ops += 1
    return ops


ops = selection_sort(arr)
print(arr)
print(ops)
