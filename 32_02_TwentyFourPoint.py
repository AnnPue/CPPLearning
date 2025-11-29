import itertools

def can_make_24(nums):
    # 生成四个数字的所有唯一排列（考虑重复数字）
    unique_perms = set(itertools.permutations(nums))
    # 定义四个运算符对应的函数，除法处理除零和浮点数
    ops = [
        lambda a, b: a + b,
        lambda a, b: a - b,
        lambda a, b: a * b,
        lambda a, b: a / b if b != 0 else float('inf')  # 除零返回无穷大（非法）
    ]
    op_indices = itertools.product([0, 1, 2, 3], repeat=3)  # 三个运算符的所有组合
    
    for perm in unique_perms:
        a, b, c, d = perm
        for op1, op2, op3 in op_indices:
            # 情况1: ((a op1 b) op2 c) op3 d
            res1 = ops[op1](a, b)
            res2 = ops[op2](res1, c)
            res3 = ops[op3](res2, d)
            if abs(res3 - 24) < 1e-6:
                return True
            # 情况2: (a op1 (b op2 c)) op3 d
            res1 = ops[op2](b, c)
            res2 = ops[op1](a, res1)
            res3 = ops[op3](res2, d)
            if abs(res3 - 24) < 1e-6:
                return True
            # 情况3: a op1 ((b op2 c) op3 d)
            res1 = ops[op2](b, c)
            res2 = ops[op3](res1, d)
            res3 = ops[op1](a, res2)
            if abs(res3 - 24) < 1e-6:
                return True
            # 情况4: a op1 (b op2 (c op3 d))
            res1 = ops[op3](c, d)
            res2 = ops[op2](b, res1)
            res3 = ops[op1](a, res2)
            if abs(res3 - 24) < 1e-6:
                return True
            # 情况5: (a op1 b) op2 (c op3 d)
            res1 = ops[op1](a, b)
            res2 = ops[op3](c, d)
            res3 = ops[op2](res1, res2)
            if abs(res3 - 24) < 1e-6:
                return True
    return False

n = int(input())
for _ in range(n):
    nums = list(map(int, input().split()))
    print("Yes" if can_make_24(nums) else "No")
