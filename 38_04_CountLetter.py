while True:
    s = input().strip()
    if s == "END":
        break
    # 初始化计数字典
    count = {}
    # 遍历字符串中的每个字符（统一转为小写）
    for char in s.lower():
        # 只统计字母
        if char.isalpha():
            count[char] = count.get(char, 0) + 1
    # 按次数降序排序，次数相同则按字母升序排序
    sorted_counts = sorted(count.items(), key=lambda x: (-x[1], x[0]))
    # 输出结果
    for char, cnt in sorted_counts:
        print(f"{char}:{cnt}")