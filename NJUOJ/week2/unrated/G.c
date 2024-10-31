#include<stdio.h>

int n,k;
char s[10000005];
int main(){
    scanf("%d\n",&n);
    fgets(s, sizeof(s), stdin);
    scanf("%d",&k);
    for(int i=k-1;i>=0;i--){
        printf("%c", s[i]);
    }
    for(int i=n-1;i>=k;i--){
        printf("%c", s[i]);
    }
}