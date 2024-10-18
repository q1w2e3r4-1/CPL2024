#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    int ge = x % 10;
    int shi = x / 10;
    shi = shi % 10;
    int bai = x / 100;

    int ans = ge * 100 + shi * 10 + bai * 1;
    printf("%d",ans);
}