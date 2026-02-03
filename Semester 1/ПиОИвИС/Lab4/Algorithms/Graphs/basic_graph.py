graphData = ['A', 'B', 'C', 'D']

adjacencyMatrix = [
    [0, 1, 1, 1],  # Edges for A
    [1, 0, 1, 0],  # Edges for B
    [1, 1, 0, 0],  # Edges for C
    [1, 0, 0, 0]   # Edges for D
]


def print_adjacency_matrix(matrix):
    for row in matrix:
        print(row)


def print_connections(graphData, matrix):
    for i, row in enumerate(matrix):
        for j, edge in enumerate(row):
            if edge:
                print(graphData[i], '-', graphData[j])


print_adjacency_matrix(adjacencyMatrix)
print_connections(graphData, adjacencyMatrix)
