#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T;
char tmp[5];

typedef struct Card{
    int pts;
    char suit;
}Card;
Card A[10], B[10];

int cmp(const void* a, const void* b){
    Card* p1 = (Card*) a;
    Card* p2 = (Card*) b;
    if(p1->pts > p2->pts) return -1;
    if(p1->pts < p2->pts) return 1;
    return 0;
}

Card input(){
    Card ret;

    scanf("%s", tmp);
    ret.suit = tmp[1];
    char c = tmp[0];
    if(c >= '2' && c <= '9'){
        ret.pts = c - '0';
    }
    else if(c == 'T'){
        ret.pts = 10;
    }
    else if(c == 'J'){
        ret.pts = 11;
    }
    else if(c == 'Q'){
        ret.pts = 12;
    }
    else if(c == 'K'){
        ret.pts = 13;
    }
    else if(c == 'A'){
        ret.pts = 14;
    }
    else{
        printf("xxxxxxx\n");
    }
    return ret;
}

int is_four();
int is_full_house();
int is_straight();
int is_three();
int is_two_pair();
int is_one_pair();
int is_flush(Card card[]);
int is_straight_flush(Card card[]);

int cnt[20];
void cal(Card card[]){
    // cal cnt of every point
    for(int i=0;i<20;i++){
        cnt[i] = 0;
    }

    for(int i=1;i<=5;i++){
        int x = card[i].pts;
        cnt[x] ++;
    }
}

int get_paixing(Card card[]){
    // printf("Before sort\n");
    for(int i=1;i<=5;i++){
        card[i] = input();
        // printf("%d%c ", card[i].pts, card[i].suit);
    }
    qsort(card+1, 5, sizeof(Card), cmp);
    // printf("\nAfter sort\n");
    // for(int i=1;i<=5;i++){
    //     printf("%d%c ", card[i].pts, card[i].suit);
    // }
    // printf("\n===============\n");
    cal(card);

    if(is_straight_flush(card)){
        return 10;
    }
    else if(is_four()){
        return 9;
    }
    else if(is_full_house()){
        return 8;
    }
    else if(is_flush(card)){
        return 7;
    }
    else if(is_straight()){
        return 6;
    }
    else if(is_three()){
        return 5;
    }
    else if(is_two_pair()){
        return 4;
    }
    else if(is_one_pair()){
        return 3;
    }
    else{
        return 2;
    }
    return -1;
}

void solve(){
    int Alice = get_paixing(A);
    int Bob = get_paixing(B);
    if(Alice < Bob){
        printf("Bob\n");
    }
    else if(Alice > Bob){
        printf("Alice\n");
    }
    else{
        // pin dian
        for(int i=1;i<=5;i++){
            if(A[i].pts < B[i].pts){
                printf("Bob\n");
                return;
            }
            else if(A[i].pts > B[i].pts){
                printf("Alice\n");
                return;
            }
        }
        printf("Tie\n");
    }
}

int main() {
    scanf("%d", &T);
    while(T--){
        solve();
    }
}

int is_four(){
    for(int i=2;i<=14;i++){
        if(cnt[i] == 4){
            return 1;
        }
    }
    return 0;
}

int is_full_house(){
    int c2 = 0, c3 = 0;
    for(int i=2;i<=14;i++){
        if(cnt[i] == 3){
            c3 ++;
        }
        if(cnt[i] == 2){
            c2 ++;
        }
    }

    if(c2 && c3) return 1;
    return 0;
}

int is_straight(){
    // 12345,23456,34567,45678,56789,6789T
    cnt[1] = cnt[14];
    for(int i=14;i>=5;i--){
        int flag = 1;
        for(int j=1;j<=5;j++){
            if(cnt[i-j+1] != 1){
                flag = 0;
            }
        }

        if(flag){
            return 1;
        }
    }

    return 0;
}

int is_three(){
    for(int i=2;i<=14;i++){
        if(cnt[i] == 3){
            return 1;
        }
    }
    return 0;
}

int is_two_pair(){
    int c = 0;
    for(int i=2;i<=14;i++){
        if(cnt[i] == 2){
            c++;
        }
    }

    if(c == 2) return 1;
    return 0;
}

int is_one_pair(){
    for(int i=2;i<=14;i++){
        if(cnt[i] == 2){
            return 1;
        }
    }
    return 0;
}

int is_flush(Card card[]){
    int success = 1;
    for(int i=1;i<=5;i++){
        if(card[i].suit != card[1].suit) success = 0;
    }
    return success;
}

int is_straight_flush(Card card[]){
    return is_flush(card) && is_straight();
}