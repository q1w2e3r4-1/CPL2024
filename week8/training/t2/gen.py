import random

def generate_deck():
    ranks = ['2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']
    suits = ['H', 'S', 'C', 'D']  # 四种花色
    return [rank + suit for rank in ranks for suit in suits]

def deal_hand(deck):
    random.shuffle(deck)
    hand = deck[:5]
    # 对手牌进行排序，确保'A'是最大的，'2'是最小的
    # 排序时先根据牌面大小排序，再根据花色排序
    # hand.sort(key=lambda x: ('2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A').index(x[0]), reverse=True)
    # hand.sort(key=lambda x: x[1])  # 根据花色排序，这里只是示例，实际效果取决于花色的具体排序需求
    return hand

def display_hand(hand):
    # 显示点数和花色
    return ' '.join(hand)

if __name__ == "__main__":
    T = 100000
    print(T)
    while T != 0:
        deck = generate_deck()
        hand = deal_hand(deck)
        print(display_hand(hand))
        T -= 1
