#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int cnt = 0;
    int max = n;
    while(n != 1){
        cnt ++;
        if(n % 2 == 1){
            n = 3*n+1;
        }
        else{
            n = n / 2;
        }

        if(n > max){
            max = n;
        }
    }    

    printf("%d %d",cnt, max);
}