#include<stdio.h>
int a[11];

int main(){
    int h;
    for(int i=1;i<=10;i++){
        scanf("%d",&a[i]);
    }

    scanf("%d", &h);
    h += 30;

    int ans = 0;
    for(int i=1;i<=10;i++){
        if(h >= a[i])
        {
            ans ++;
        }
    }
    printf("%d", ans);
}