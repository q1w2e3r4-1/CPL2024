
import random

def generate_deck():
    # suits = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
    # ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'Jack', 'Queen', 'King', 'Ace']
    # return [{'suit': suit, 'rank': rank} for suit in suits for rank in ranks]

    ranks = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
    return [i for i in ranks for j in range(4)]

def deal_hand(deck):
    random.shuffle(deck)
    hand = deck[:5]
    hand.sort(reverse=True)
    return hand

def display_hand(hand):
    return ' '.join(['{} of {}'.format(card['rank'], card['suit']) for card in hand])

if __name__ == "__main__":
    T = 100000
    print(T)
    while T != 0:
        deck = generate_deck()
        hand = deal_hand(deck)
        print(' '.join(hand))
        T -= 1