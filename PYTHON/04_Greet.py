def greet(name = "World"):  # 默认参数是 "World"
    print (f"Hello, {name}!")

greet()         # 使用默认参数，输出: Hello, World!
greet("Alice")  # 提供参数，输出: Hello, Alice!