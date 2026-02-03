class HashMap:
    def __init__(self, size=10):
        self.size = size
        self._curr_size = 0
        self.buckets = [[] for _ in range(size)]

    def hash_function(self, key):
        numeric_sum = sum(int(char) for char in str(key) if char.isdigit())
        return numeric_sum % 10

    def put(self, key, value):
        hash = self.hash_function(key)
        bucket = self.buckets[hash]

        for i, (k, v) in enumerate(bucket):
            if (k == key):
                bucket[i] = (k, value)
                return
        bucket.append((key, value))

    def remove(self, key):
        hash = self.hash_function(key)
        bucket = self.buckets[hash]

        for i, (k, v) in enumerate(bucket):
            if (k == key):
                del bucket[i]
                break

    def get(self, key):
        hash = self.hash_function(key)
        bucket = self.buckets[hash]

        for (k, v) in bucket:
            if (k == key):
                return v
        return None

    def get_size(self):
        return sum(len(bucket) for bucket in self.buckets)

    def print_map(self):
        print('Hash Map Contents: ')
        for i, bucket in enumerate(self.buckets):
            print(f'{i}:', end=' ')
            for (k, v) in bucket:
                print(f'{k} : {v}', end='\t')
            print()


map = HashMap()

map.put(123, 'Goose')
map.put(145, 'Daniil')
map.put(167, 'Kusachka')

map.print_map()

map.remove(167)

map.print_map()

print(map.get_size())
