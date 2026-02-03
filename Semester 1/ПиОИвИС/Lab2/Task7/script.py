import json
from json2html import *

input = json.loads(open("books.json", encoding="utf-8").read())

open("output.html", "w").write(json2html.convert(json = input))

print(json2html.convert(json = input))