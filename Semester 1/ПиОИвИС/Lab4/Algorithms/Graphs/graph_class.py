class Graph:
    def __init__(self, size):
        self.adj_matr = [[0] * size for _ in range(size)]
        self.size = size
        self.vertex_data = [''] * size
        self.parent = [i for i in range(size)]

    def add_edge(self, u, v):
        if 0 <= u < self.size or 0 <= v < self.size:
            self.adj_matr[u][v] = 1
            self.adj_matr[v][u] = 1

    def add_vertex_data(self, vertex, data):
        if 0 <= vertex <= self.size:
            self.vertex_data[vertex] = data

    def print_graph(self):
        print('Adjacency matrix: ')
        for row in self.adj_matr:
            print(' '.join(map(lambda x: str(x) if x is not None else '0', row)))
        print('Vertex Data: ')
        for vert, data in enumerate(self.vertex_data):
            print(f'Vertex {vert}: {data}')

    def dfs_util(self, vertex, visited):
        visited[vertex] = True
        print(self.vertex_data[vertex], end=' ')

        for i in range(self.size):
            if self.adj_matr[vertex][i] == 1 and not visited[i]:
                self.dfs_util(i, visited)

    # For detecting cycles
    def dfs_util(self, vertex, visited, parent):
        visited[vertex] = True

        for i in range(self.size):
            if not visited[i]:
                if self.dfs_util(i, visited, vertex):
                    return True
            elif parent != i:
                return True
        return False

    def is_cycling(self):
        visited = [False] * self.size
        for i in range(self.size):
            if not visited[i]:
                if self.dfs_util(i, visited, -1):
                    return True
        return False

    def find(self, i):
        if (self.parent[i] == i):
            return i
        return self.find(self.parent[i])  # [1, 2, 2, 4, 5]

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)

        print(f'Union {self.vertex_data[x]} + {self.vertex_data[y]}:')
        self.parent[x_root] = y_root
        print(self.parent, '\n')

    def union_is_cycling(self):
        for i in range(self.size):
            for j in range(i+1, self.size):
                if self.adj_matr[i][j]:
                    x = self.find(i)
                    y = self.find(j)
                    if x == y:
                        return True
                    self.union(x, y)
        return True

    def dfs(self, start_vertex_data):
        visited = [False] * self.size
        start_vertex = self.vertex_data.index(start_vertex_data)

        self.dfs_util(start_vertex, visited)

    def bfs(self, start_vertex_data):
        queue = [self.vertex_data.index(start_vertex_data)]
        visited = [False] * self.size
        visited[queue[0]] = True

        while queue:
            current = queue.pop(0)
            print(self.vertex_data[current], end=' ')

            for i in range(self.size):
                if self.adj_matr[current][i] == 1 and not visited[i]:
                    queue.append(i)
                    visited[i] = True


graph = Graph(5)
graph.add_vertex_data(0, 'A')
graph.add_vertex_data(1, 'B')
graph.add_vertex_data(2, 'C')
graph.add_vertex_data(3, 'D')
graph.add_vertex_data(4, 'E')

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 2)
graph.add_edge(4, 0)
graph.add_edge(3, 2)

graph.print_graph()
print(graph.union_is_cycling())
