import xml.etree.ElementTree as ET


def add_book(title, author, isbn, root):
    new_book_el = ET.Element("book", {"id": str(4)})

    title_el = ET.Element("title")
    title_el.text = title

    author_el = ET.Element("author")
    author_el.text = author

    isbn_el = ET.Element("isbn")
    isbn_el.text = isbn

    new_book_el.append(title_el)
    new_book_el.append(author_el)
    new_book_el.append(isbn_el)

    root.append(new_book_el)


def print_book_list(root):
    for child in root:
        print(f"Book #{child.attrib["id"]}:")
        for tag in child:
            print(f"\t{tag.tag.capitalize()}: {tag.text}")


parsed_xml = ET.parse("file.xml")

# add_book("Blood Meridian", "Comac McCarthy", "32795235", parsed_xml.getroot())

print_book_list(parsed_xml.getroot())

parsed_xml.write("file.xml")
