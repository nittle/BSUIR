from yaml import load, dump
from yaml import CLoader as Loader, CDumper as Dumper

data = load(open("file.yml", "r", encoding="UTF-8"), Loader=Loader)

data["readers"].append({"name": "Goose", "borrowed_books": [8, 9, 10]})

for reader in data["readers"]:
    print(f"Name: {reader["name"]}")
    print(f"\tBorrowed books: {reader["borrowed_books"]}")

dump(data, open("file.yml", "w", encoding="UTF-8"))
