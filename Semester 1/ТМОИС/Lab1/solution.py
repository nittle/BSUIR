import math


def does_contain(array, element):
    for el in array:
        if (el == element):
            return True
    return False


def union(a, b):
    c = a.copy()
    for el in b:
        if (not does_contain(c, el)):
            c.append(el)
    return c


def difference(a, b):
    c = a.copy()
    for el in b:
        isContained = does_contain(c, el)
        if (isContained):
            c.remove(el)
    return c


def intersection(a, b):
    c = []
    for el in a:
        if (does_contain(b, el)):
            c.append(el)
    return c


def symmetric_difference(a, b):
    dif1 = difference(a, b)
    dif2 = difference(b, a)
    c = union(dif1, dif2)
    return c


def addition(a, b):
    for el in a:
        if (not does_contain(b, el)):
            return "Error"

    dif = difference(b, a)
    return dif


def partition(a, b):
    if (b > len(a)):
        return "Error"

    amount_of_elements = []
    elements_left = len(a)
    for i in range(b):
        if (i == b - 1):
            amount_of_elements.append(elements_left)
        else:
            add = math.floor(len(a) / b)
            elements_left -= add
            amount_of_elements.append(add)

    c = []
    next_ind = 0

    for setLength in amount_of_elements:
        temp = []
        for k in range(setLength):
            temp.append(a[next_ind])
            next_ind += 1
        c.append(temp)

    return c


print("1 - union\n2 - difference\n3 - intersection\n4 - symmetric difference\n5 - additon\n6 - partition\n")
op = input("Operation: ").strip()
result = []

match op:
    case "5":
        print("Where a is a set, b is a superset")
    case "6":
        print("Where a is a set, b is a number of subsets")
    case _:
        print("Where a and b are sets")

a = sorted(input("Enter a: ").split())
b = sorted(input("Enter b: ").split())

match op:
    case "1":
        result = union(a, b)
    case "2":
        result = difference(a, b)
    case "3":
        result = intersection(a, b)
    case "4":
        result = symmetric_difference(a, b)
    case "5":
        result = addition(a, b)
    case "6":
        result = partition(a, int(b[0]))

print("Result: " + str(result))
