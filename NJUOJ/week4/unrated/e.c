#include<stdio.h>

char ans[1005][1005];
char s[1005];
int n;
int cnt[128];

int row = 0, col = 0;
int main(){
    scanf("%d %s",&n, s);
    for(int i=0;i<n;i++){
        char c = s[i];
        cnt[c] ++;
    }

    for(int i=0;i<26;i++){
        char lower = i + 'a';
        char upper = i + 'A';
        if(cnt[lower] != 0 || cnt[upper] != 0){
            if(cnt[lower]){
                ans[0][col] = lower;
                col ++;
            }
            if(cnt[upper]){
                ans[0][col] = upper;
                col ++;
            }
            ans[0][col] = ' ';
            col ++;
        }
    }
    
    for(int i='a'; i<='z';i++){
        if(cnt[i] > row){
            row = cnt[i];
        }
    }
    for(int i='A'; i<='Z';i++){
        if(cnt[i] > row){
            row = cnt[i];
        }
    }

    for(int i=1;i<=row;i++){
        for(int j=0;j<col;j++){
            char now = ans[0][j];
            if(now == ' '){
                ans[i][j] = ' ';
            }
            else{
                int x = cnt[now];
                if(x >= i){
                    ans[i][j] = '=';
                }
                else{
                    ans[i][j] = ' ';
                }
            }
        }
    }

    for(int i=row;i>=1;i--){
        printf("%s\n",ans[i]);
    }
    for(int i=0;i<col-1;i++){
        printf("-");
    }
    printf("\n");
    printf("%s \n", ans[0]);
}