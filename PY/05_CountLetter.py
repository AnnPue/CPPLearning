from collections import Counter

def main():
    """主函数：程序入口"""
    print("读取一行字符串，统计串中每个字母出现的次数，大小写不区分，然后按照出现次数从大到小输出。")
    print("输入END程序结束。")
    # 预定义26个小写字母（确保未出现的字母也能显示，与原逻辑一致）
    # ord() 函数返回字符的 ASCII 值
    # chr() 函数返回 ASCII 值对应的字符
    all_letters = [chr(ord('a') + i) for i in range(26)]
    
    while True:
        # 读取输入并去除首尾空白
        input_str = input().strip()
        
        # 退出条件：不区分大小写判断
        if input_str == 'END':
            break
        # 如果输入为空，则继续读取输入
        if not input_str:
            continue
        
        # 回显字符串
        print(f"字符串s1的长度是{len(input_str)}，内容是：{input_str}")
        
        # 1. 转小写，仅保留字母字符
        lower_chars = [c.lower() for c in input_str if c.isalpha()]
        
        # 2. 使用Counter快速计数（Python内置计数工具，效率更高）
        letter_counter = Counter(lower_chars)
        
        # 3. 初始化所有26个字母的计数（确保未出现的字母次数为0）
        full_letter_count = {ch: letter_counter.get(ch, 0) for ch in all_letters}
        
        # 4. 按次数降序排序
        # items() 方法返回一个包含所有（键，值）元组的列表
        # key=lambda x: x[1] 表示按元组第二个元素（出现次数）排序
        # reverse=True 表示降序排序
        sorted_letter_items = sorted(full_letter_count.items(), key=lambda x: x[1], reverse=True)
        
        # 5. 输出结果
        for ch, cnt in sorted_letter_items:
            print(f"{ch}出现的次数是{cnt}次。")

if __name__ == '__main__':  # 如果当前模块是主模块，则执行main函数
    main()
