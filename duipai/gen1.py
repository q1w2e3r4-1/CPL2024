import random

T = random.randint(1, 10)
while T:
    T -= 1

    # 生成一个在[0, 1e100]之间的随机整数
    a = random.randint(0, int(1e100))
    b = random.randint(0, int(1e100))
    ops = ['+', '-', '*', '/']
    op = random.choice(ops)
    print(a, op, b)
