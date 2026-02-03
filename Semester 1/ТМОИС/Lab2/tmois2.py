from random import randint


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

    def append(self, el1: int, el2: int):
        self.__curr_set.append([el1, el2])

    def print_set(self):
        print('{ ', end='')
        if (len(self.__curr_set) == 0):
            print('∅ ', end='')
        else:
            for el in self.__curr_set:
                print(f'<{el[0]}, {el[1]}> ', end='')
        print('}\n', end='')

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


max = int(input('Input max value of elements in graphs: '))
size1 = int(input('Input size of graph 1: '))
size2 = int(input('Input size of graph 2: '))

if (size1 % 2 != 0 or size2 % 2 != 0):
    print('One of the sizes is not even, therefore the actual size will be reduced by 1')

gr1 = graph([randint(0, max) for _ in range(size1)])
gr2 = graph([randint(0, max) for _ in range(size2)])

print('Graph 1:')
gr1.print_set()

print('Graph 2: ')
gr2.print_set()

print('Projection of graph 1 on to axis 1: ')
print(graph.projection(gr1, 1))

print('Projection of graph 1 on to axis 2: ')
print(graph.projection(gr1, 2))

print('Projection of graph 2 on to axis 1: ')
print(graph.projection(gr2, 1))

print('Projection of graph 2 on to axis 2: ')
print(graph.projection(gr2, 2))

print('Graph 1 inverted: ')
graph.inversion(gr1).print_set()

print('Graph 2 inverted: ')
graph.inversion(gr2).print_set()

print('Composition of graph 1 and graph 2: ')
graph.composition(gr1, gr2).print_set()

print('Composition of graph 2 and graph 1: ')
graph.composition(gr2, gr1).print_set()
