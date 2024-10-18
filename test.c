#include<stdio.h>
#include<string.h>

int n;
char s[20];

int main(){
    int score = 0;
    int max_combo = 0;
    int combo = 0;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s", s);
        if(strcmp(s, "Perfect") == 0){
            int base = 10;
            int bonus = 10 + combo;
            if(bonus > 30){
                bonus = 30;
            }

            score += base * bonus;
            combo ++;
            if(combo > max_combo){
                max_combo = combo;
            }
        }
        else if(strcmp(s, "Great") == 0){
            int base = 5;
            int bonus = 10 + combo;
            if(bonus > 30){
                bonus = 30;
            }

            score += base * bonus;
            combo ++;
            if(combo > max_combo){
                max_combo = combo;
            }
        }
        else if(strcmp(s, "Good") == 0){
            int base = 2;
            int bonus = 10 + combo;
            if(bonus > 30){
                bonus = 30;
            }

            score += base * bonus;
            combo ++;
            if(combo > max_combo){
                max_combo = combo;
            }
        }
        else{
            // Miss
            combo = 0;
        }
        // printf("%d %d\n",score, max_combo);
    }

    printf("%d %d",score, max_combo);
}