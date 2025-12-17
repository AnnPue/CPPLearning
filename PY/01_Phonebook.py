names = ["alice", "bob", "charlie", "diana"]

name = input("Enter a name: ").lower()

for _ in names:
    if name == _:
        print(f"{name.capitalize()} is in the list.")
        break
else:
    print(f"{name.capitalize()} is not in the list.")