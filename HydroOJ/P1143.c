#include<stdio.h>
#include<string.h>

int len, n, m;
char s[35];
char t[35];
int main(){
    scanf("%d %s %d", &n, s, &m);
    int len = strlen(s);
    long long ans = 0;

    for(int i=0;i<len;i++){
        int x = -1;
        if(s[i] >= '0' && s[i] <= '9'){
            x = s[i] - '0';
        }
        else{
            x = s[i] - 'A' + 10;
        }

        if(x >= n){
            printf("Error\n");
            return 0;
        }
        ans *= n;
        ans += x;
    }
    

    // 10-base -> m-base
    // printf("%d\n",ans);
    if(ans == 0){
        printf("0");
        return 0;
    }

    int len1 = 0;
    while(ans){
        t[len1] = ans % m;
        ans /= m;
        len1 ++;
    }

    for(int i = len1 - 1 ; i >= 0; i--){
        if(t[i] >= 0 && t[i] <= 9){
            printf("%d", t[i]);
        }   
        else{
            char c = t[i] - 10 + 'A';
            printf("%c", c);
        }
    }
}