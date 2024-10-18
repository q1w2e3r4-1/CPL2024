#include<stdio.h>
int main(){
    int m;
    scanf("%d",&m);
    if(m > 100){
        printf("Wrong score\n");
    }
    else if(m >= 90 && m <= 100){
        printf("A\n");
    }
    else if(m >= 80 && m <= 89){
        printf("B\n");
    }
    else if(m >= 70 && m <= 79){
        printf("C\n");
    }
    else if(m >= 60 && m <= 69){
        printf("D\n");
    }
    else if(m < 60){
        printf("F\n");
    }
}