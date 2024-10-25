#include<stdio.h>

int cnt[10],T;
int a[10];

int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=9;i++) cnt[i] = 0;
        for(int i=1;i<=5;i++) scanf("%d", &a[i]);
        for(int i=1;i<=5;i++){
            cnt[a[i]] ++;
        }
        
        int two = 0, three = 0, four = 0;
        int two_idx1 = -1, two_idx2 = -1, three_idx = -1, four_idx = -1;
        for(int i=9;i>=1;i--){
            if(cnt[i] == 2){
                two ++;
                if(two_idx1 == -1) two_idx1 = i;
                else two_idx2 = i;
            }
            if(cnt[i] == 3) three ++, three_idx = i;
            if(cnt[i] == 4) four ++, four_idx = i;
        }
        
        if(four == 1){
            printf("Four of a Kind(%d)\n", four_idx);    
        }
        else if(three == 1 && two == 1){
            printf("Full House(%d,%d)\n", three_idx, two_idx1);
        }
        else if(three == 1){
            printf("Three of a Kind(%d)\n", three_idx);
        }
        else if(two == 2){
            printf("Two Pairs(%d,%d)\n", two_idx1, two_idx2);
        }
        else if(two == 1){
            printf("One Pair(%d)\n", two_idx1);
        }
        else{
            printf("High Card\n");
        }
        
    }
}