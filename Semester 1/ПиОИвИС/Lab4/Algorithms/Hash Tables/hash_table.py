class HashTable:
    def __init__(self, size=10):
        self.size = size
        self._table = [[] for _ in range(size)]

    def add(self, key):
        hash = self._hashFunction(key)
        bucket = self._table[hash]
        if key not in bucket:
            bucket.append(key)

    def contains(self, key):
        hash = self._hashFunction(key)
        bucket = self._table[hash]
        return key in bucket

    def delete(self, key):
        hash = self._hashFunction(key)
        bucket = self._table[hash]
        if (key in bucket):
            bucket.remove(key)

    @staticmethod
    def _hashFunction(key):
        sum_of_chars = 0
        for char in key:
            sum_of_chars += ord(char)
        return sum_of_chars % 10


table = HashTable()
table.add('Goose')
table.add('Kusachka')
table.add('Nikitos')
print(table._table)
print(table.contains('Goose'))
print(table.contains('Hello'))

table.delete('Nikitos')
print(table._table)
