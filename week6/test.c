#include<stdio.h>

enum Suit{
    Heart, Diamond, Spade, Clubs
};

typedef struct Card{
    enum Suit suit;
    int point;
}Card;

Card card[10005];

int main(){
    if(card[0].suit == 0){

    }
}

// 3S 4H 5D 6C
