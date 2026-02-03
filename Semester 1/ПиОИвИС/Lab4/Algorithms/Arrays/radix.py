import math


def radix(arr):
    # count num of digits of max array element
    # loop which sorts all elms into radix array according to first digit
    # to 2nd digit
    # ... to the last one
    n = len(arr)
    num_of_digits = int(math.log10(max(arr))) + 1
    temp = []
    for i in range(0, num_of_digits):
        radix_arr = [[] for _ in range(10)]
        for j in range(n):
            curr_val = arr[j]
            curr_rad = curr_val // (10**i) % 10
            radix_arr[curr_rad].append(curr_val)
        for els in radix_arr:
            temp.extend(els)
        arr[:] = temp
        temp = []


arr = [11, 24, 69, 45, 78, 38, 40]
radix(arr)
print(arr)
