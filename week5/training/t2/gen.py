import random
import sys

def generate_test_data():
    # 随机生成N的值，符合题目给定的范围
    N = random.randint(3, 100)
    # 随机生成Q的值，符合题目给定的范围
    Q = random.randint(1, 100)

    # 初始左手和右手的位置
    left_hand = 1
    right_hand = 2

    # 输出N和Q
    print(f"{N} {Q}")

    # 生成Q个指令
    for _ in range(Q):
        # 随机选择移动左手或右手
        hand = random.choice(['L', 'R'])
        # 确定目标位置，避免无效操作
        if hand == 'L':
            # 左手不能移到右手上
            target = random.choice([i for i in range(1, N+1) if i != right_hand])
        else:
            # 右手不能移到左手上
            target = random.choice([i for i in range(1, N+1) if i != left_hand])
        
        # 更新手的位置
        if hand == 'L':
            left_hand = target
        else:
            right_hand = target
        
        # 输出指令
        print(f"{hand} {target}")

# 主函数，当脚本直接运行时调用
if __name__ == "__main__":
    generate_test_data()