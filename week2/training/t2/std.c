#include<stdio.h>

int main(){
    unsigned long long year,k;
    scanf("%llu %llu",&year, &k);
    
    unsigned long long y1 = year;
    unsigned long long y2 = year + k;
    if(y1 % 4 != 0){
        printf("Normal year!\n");
    }
    else if(y1 % 100 != 0){
        printf("Leap year!\n");
    }
    else if(y1 % 400 != 0){
        printf("Normal year!\n");
    }
    else{
        printf("Leap year!\n");
    }
    
    if(y2 % 4 != 0){
        printf("Normal year!\n");
    }
    else if(y2 % 100 != 0){
        printf("Leap year!\n");
    }
    else if(y2 % 400 != 0){
        printf("Normal year!\n");
    }
    else{
        printf("Leap year!\n");
    }
}