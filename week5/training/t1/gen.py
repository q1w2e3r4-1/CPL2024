import random

def generate_deck():
    ranks = ['2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']
    return [rank for rank in ranks for _ in range(4)]

def deal_hand(deck):
    random.shuffle(deck)
    hand = deck[:5]
    # 对手牌进行排序，确保'A'是最大的，'2'是最小的
    hand.sort(key=lambda x: ('2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A').index(x), reverse=True)
    return hand

def display_hand(hand):
    # 由于没有花色，这里只显示点数
    return ' '.join(hand)

if __name__ == "__main__":
    T = 100000
    print(T)
    while T != 0:
        deck = generate_deck()
        hand = deal_hand(deck)
        print(display_hand(hand))
        T -= 1
