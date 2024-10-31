#include<stdio.h>

int len, n;
char s[35];
int main(){
    scanf("%d %d %s", &len, &n, s);
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

    printf("%d\n",ans);
}