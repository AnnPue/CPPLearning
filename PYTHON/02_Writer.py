import csv
name = input("Name: ")
number = input("Number: ")
file_path = r".\PY\phonebook.csv"
with open(file_path, 'a', encoding='utf-8') as file:
    writer = csv.DictWriter(file, fieldnames=['name', 'number'])
    writer.writerow({'name': name, 'number': number})
