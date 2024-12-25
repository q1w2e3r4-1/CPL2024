#include <stdio.h>
#include <string.h>

int T;
char tmp[5];

typedef struct Card{
    int pts;
    char suit;
}Card;
Card card[10];

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
int is_flush();
int is_straight_flush();

int cnt[20];
void cal(){
    // cal cnt of every point
    for(int i=0;i<20;i++){
        cnt[i] = 0;
    }

    for(int i=1;i<=5;i++){
        int x = card[i].pts;
        cnt[x] ++;
    }
}

void solve(){
    for(int i=1;i<=5;i++){
        card[i] = input();
    }
    cal();

    if(is_straight_flush()){
        printf("Straight Flush\n");
    }
    else if(is_four()){
        printf("Four of a Kind\n");
    }
    else if(is_full_house()){
        printf("Full House\n");
    }
    else if(is_flush()){
        printf("Flush\n");
    }
    else if(is_straight()){
        printf("Straight\n");
    }
    else if(is_three()){
        printf("Three of a Kind\n");
    }
    else if(is_two_pair()){
        printf("Two Pairs\n");
    }
    else if(is_one_pair()){
        printf("One Pair\n");
    }
    else{
        printf("High Card\n");
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

int is_flush(){
    int success = 1;
    for(int i=1;i<=5;i++){
        if(card[i].suit != card[1].suit) success = 0;
    }
    return success;
}

int is_straight_flush(){
    return is_flush() && is_straight();
}