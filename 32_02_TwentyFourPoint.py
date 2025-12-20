import itertools

def can_make_24(nums):
    # 递归终止条件：只剩一个数字，判断是否接近24
    if len(nums) == 1:
        return abs(nums[0] - 24) < 1e-6
    
    # 枚举所有两两数字的组合（不重复）
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            a = nums[i]
            b = nums[j]
            # 剩余未选中的数字
            rest = [nums[k] for k in range(len(nums)) if k != i and k != j]
            
            # 枚举a和b的所有四则运算结果（覆盖所有可能的运算组合）
            # 1. 加法（a+b 和 b+a结果一致，无需重复计算）
            if can_make_24(rest + [a + b]):
                return True
            # 2. 减法（两种情况：a-b 和 b-a）
            if can_make_24(rest + [a - b]):
                return True
            if can_make_24(rest + [b - a]):
                return True
            # 3. 乘法（a*b 和 b*a结果一致，无需重复计算）
            if can_make_24(rest + [a * b]):
                return True
            # 4. 除法（两种情况：a/b 和 b/a，需做除零保护）
            if b != 0 and can_make_24(rest + [a / b]):
                return True
            if a != 0 and can_make_24(rest + [b / a]):
                return True
    # 所有组合都尝试过，无法得到24
    return False

# 输入输出处理
n = int(input())  # 谜题数量
for _ in range(n):
    nums = list(map(int, input().split()))  # 读取四个整数
    # 转换为浮点数，避免整数除法截断（Python3中/是浮点除法，//是整数除法）
    float_nums = [float(num) for num in nums]
    print("Yes" if can_make_24(float_nums) else "No")
