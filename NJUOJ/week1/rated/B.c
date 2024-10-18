#include<stdio.h>

int main(){
    int money;
    scanf("%d",&money);
    int a1=0,a2=0,a3=0,a4=0,a5=0;
    while(money >= 50){
        money -= 50;
        a1 ++;
    }

    while(money >= 20){
        money -= 20;
        a2 ++;
    }

    while(money >= 10){
        money -= 10;
        a3 ++;
    }

    while(money >= 5){
        money -= 5;
        a4 ++;
    }

    while(money >= 1){
        money -= 1;
        a5 ++;
    }
    printf("%d\n%d\n%d\n%d\n%d",a1,a2,a3,a4,a5);
}