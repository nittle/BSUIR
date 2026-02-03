from random import randint

num = int(input('Input num of elmts: '))

arr = []

for _ in range(num):
    arr.append(randint(1, 100))


def partition(arr, low, high):
    # set pivot point to the last element
    pivot = arr[high]
    # position of the pivot found so far
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1


def quick_sort(arr, low=0, high=None):

    if (high is None):
        high = len(arr) - 1

    if (low < high):
        pivot_index = partition(arr, low, high)
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)


quick_sort(arr)

print(arr)
