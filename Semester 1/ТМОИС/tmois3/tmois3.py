from random import randint
import math


class graph:
    def __init__(self, arr: list = None):
        self.__curr_set = []

        if (arr is None):
            return

        i = 1
        while (i < len(arr)):
            self.append(arr[i-1], arr[i])
            i += 2

    def __getitem__(self, ind: int):
        return self.__curr_set[ind]

    def __len__(self):
        return len(self.__curr_set)
    
    def contains(self, values):
        for i in range(len(self)):
            if(self.__curr_set[i][0] == values[0] and self.__curr_set[i][1] == values[1]):
                return True
        return False
    
    def index(self, values):
        for i in range(len(self)):
            if(self.__curr_set[i][0] == values[0] and self.__curr_set[i][1] == values[1]):
                return i
    
    def pop(self, values):
        self.__curr_set.pop(self.index(values))

    def append(self, el1: int, el2: int):
        self.__curr_set.append([el1, el2])

    def get_set_image(self, set):
        result = []
        for x in set:
            for el in self.__curr_set:
                if el[0] == x and el[1] not in result:
                    result.append(el[1])

        if len(result) == 0:
            result.append('∅')
        return result

    def print_set(self):
        print('{ ', end='')
        if (len(self.__curr_set) == 0):
            print('∅ ', end='')
        else:
            for el in self.__curr_set:
                print(f'<{el[0]}, {el[1]}> ', end='')
        print('}\n', end='')

    def to_string(self):
        result = ''
        result += '{ '
        if (len(self.__curr_set) == 0):
            result += '∅ '
        else:
            for el in self.__curr_set:
                result += f'<{el[0]}, {el[1]}> '
        result += '}\n'
        return result

    @staticmethod
    def composition(graph1, graph2):
        new_set = graph()

        for i in range(len(graph1)):
            for j in range(len(graph2)):
                if (graph1[i][1] == graph2[j][0]):
                    new_set.append(graph1[i][0], graph2[j][1])
        return new_set

    @staticmethod
    def projection(gr, axis):
        new_set = []

        for i in range(len(gr)):
            new_set.append(gr[i][axis-1])
        return new_set

    @staticmethod
    def inversion(gr):
        new_set = graph()

        for i in range(len(gr)):
            new_set.append(gr[i][1], gr[i][0])

        return new_set
    
    @staticmethod
    def union(gr1, gr2):
        new_gr = gr1
        for i in range(len(gr2)):
            if gr2[i] not in gr1:
                new_gr.append(gr2[i][0], gr2[i][1])
        return new_gr
    
    @staticmethod
    def intersection(gr1, gr2):
        new_gr = graph()
        for i in range(len(gr1)):
            if gr2.contains(gr1[i]):
                new_gr.append(gr1[i][0], gr1[i][1])
        return new_gr
    
    @staticmethod
    def difference(gr1, gr2):
        new_gr = gr1
        for i in range(len(gr2)):
            if new_gr.contains(gr2[i]):
                new_gr.pop(gr2[i])
        return new_gr

class set_operations:
    @staticmethod
    def does_contain(array, element):
        for el in array:
            if (el == element):
                return True
        return False

    @staticmethod
    def union(a, b):
        c = a.copy()
        for el in b:
            if (not set_operations.does_contain(c, el)):
                c.append(el)
        return c

    @staticmethod
    def difference(a, b):
        c = a.copy()
        for el in b:
            isContained = set_operations.does_contain(c, el)
            if (isContained):
                c.remove(el)
        return c

    @staticmethod
    def intersection(a, b):
        c = []
        for el in a:
            if (set_operations.does_contain(b, el)):
                c.append(el)
        return c

    @staticmethod
    def symmetric_difference(a, b):
        dif1 = set_operations.difference(a, b)
        dif2 = set_operations.difference(b, a)
        c = set_operations.union(dif1, dif2)
        return c

    @staticmethod
    def addition(a, b):
        for el in a:
            if (not set_operations.does_contain(b, el)):
                return "Error"

        dif = set_operations.difference(b, a)
        return dif

    @staticmethod
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
            for _ in range(setLength):
                temp.append(a[next_ind])
                next_ind += 1
            c.append(temp)

        return c

def generate_random_set(length, max_val, min_val = 1):
    # number of possible values < length 
    if max_val - min_val + 1 < length:
        print('Not possible to generate random set with given settings')
        return
    
    res = []
    for _ in range(length):
        new_el = randint(min_val, max_val)
        while new_el in res:
            new_el = randint(min_val, max_val)

        res.append(new_el)
    return res

def fill_correspondence(length_of_sets, max_val, num_of_connections, min_val = 1):
    if num_of_connections > length_of_sets ** 2:
        print('Not possible to generate so many connections')
        return

    corr = [generate_random_set(length_of_sets, max_val, min_val), 
         generate_random_set(length_of_sets, max_val, min_val), 
         graph()]

    for _ in range(num_of_connections):
        values = (corr[0][randint(0, length-1)], corr[1][randint(0, length-1)])

        while corr[2].contains(values):
            values = (corr[0][randint(0, length-1)], corr[1][randint(0, length-1)])

        corr[2].append(values[0], values[1])

    return corr


length = int(input('Enter length of sets: '))
max_val = int(input('Enter max value of elements in sets: '))
num_of_connections = int(input('Enter number of connections: '))

corr1 = fill_correspondence(length, max_val, num_of_connections)

corr2 = fill_correspondence(length, max_val, num_of_connections)

print(f'X = {corr1[0]}\nY = {corr1[1]}\nG = {corr1[2].to_string()}')
print(f'M = {corr2[0]}\nN = {corr2[1]}\nP = {corr2[2].to_string()}')
print()

print('IMAGE of X')
print(corr1[2].get_set_image(corr1[0]))
print()

print('IMAGE of Y')
print(corr1[2].get_set_image(corr1[1]))
print()

print('IMAGE of M')
print(corr2[2].get_set_image(corr2[0]))
print()

print('IMAGE of P')
print(corr2[2].get_set_image(corr2[1]))
print()

print('PREIMAGE of X')
print(graph.inversion(corr1[2]).get_set_image(corr1[0]))
print()

print('PREIMAGE of Y')
print(graph.inversion(corr1[2]).get_set_image(corr1[1]))
print()

print('PREIMAGE of M')
print(graph.inversion(corr2[2]).get_set_image(corr2[0]))
print()

print('PREIMAGE of P')
print(graph.inversion(corr2[2]).get_set_image(corr2[1]))
print()


print('UNION')
print('X∪M', set_operations.union(corr1[0], corr2[0]))
print('Y∪N', set_operations.union(corr1[1], corr2[1]))
print('G∪P', graph.union(corr1[2], corr2[2]).to_string())
print()

print('INTERSECTION')
print('X∩M', set_operations.intersection(corr1[0], corr2[0]))
print('Y∩N', set_operations.intersection(corr1[1], corr2[1]))
print('G∩P', graph.intersection(corr1[2], corr2[2]).to_string())
print()

print('DIFFERENCE of corr1 and corr2')
print('X/M', set_operations.difference(corr1[0], corr2[0]))
print('Y/N', set_operations.difference(corr1[1], corr2[1]))
print('G/P', graph.difference(corr1[2], corr2[2]).to_string())
print()

print('DIFFERENCE of corr2 and corr1')
print('M/X', set_operations.difference(corr2[0], corr1[0]))
print('N/Y', set_operations.difference(corr2[1], corr1[1]))
print('P/G', graph.difference(corr2[2], corr1[2]).to_string())
print()

print('INVERSION of corr1')
print('Y =', corr1[1])
print('X =', corr1[0])
print('G-1 =', graph.inversion(corr1[2]).to_string())
print()

print('INVERSION of corr2')
print('N =', corr2[1])
print('M =', corr2[0])
print('P-1 =', graph.inversion(corr2[2]).to_string())
print()

print('COMPOSITION of corr1 and corr2')
print('X =', corr1[0])
print('N =', corr2[1])
print('G·P =', graph.composition(corr1[2], corr2[2]).to_string())
print()

print('COMPOSITION of corr2 and corr1')
print('M =', corr2[0])
print('Y =', corr1[1])
print('P·G =', graph.composition(corr2[2], corr1[2]).to_string())
print()
