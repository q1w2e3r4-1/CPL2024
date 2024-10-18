#include<stdio.h>

int n;
char s[30];
int main(){
    scanf("%d",&n);
    int combo = 0, max_combo = 0;
    int score = 0;
    
    for(int i=1;i<=n;i++){
        scanf("%s", s);
        if(s[0] == 'P'){
            // Perfect
            int base = 100;
            int bonus = 10 + combo;
            if(bonus > 30) bonus = 30;
            score += base / 10 * bonus;

            combo ++;
        }
        else if(s[1] == 'r'){
            // Great
            int base = 50;
            int bonus = 10 + combo;
            if(bonus > 30) bonus = 30;
            score += base / 10 * bonus;

            combo ++;
        }
        else if(s[1] == 'o'){
            // Good
            int base = 20;
            int bonus = 10 + combo;
            if(bonus > 30) bonus = 30;
            score += base / 10 * bonus;

            combo ++;
        }
        else{
            // Miss
            combo = 0;
        }

        if(combo > max_combo){
            max_combo = combo;
        }
    }

    printf("%d %d",score, max_combo);
}