from random import randint

num = int(input('Input num of elmts: '))

arr = []

for _ in range(num):
    arr.append(randint(1, 100))


def insertion_sort(arr):
    n = len(arr)
    ops = 0

    for i in range(1, n):
        insert_index = i
        current_value = arr[i]

        for j in range(i - 1, -1, -1):
            if (arr[j] > current_value):
                arr[j+1] = arr[j]
                insert_index = j
                ops += 1
            else:
                break
        arr[insert_index] = current_value
    return ops


print(insertion_sort(arr))
print(arr)
