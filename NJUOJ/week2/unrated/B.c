#include<stdio.h>

int main(){
    int hour, minute;
    scanf("%d:%d",&hour, &minute);
    if(hour < 12){
        printf("%02d:%02d a.m.",hour, minute);
    }
    else if(hour == 12){
        printf("%02d:%02d p.m.",hour, minute);
    }
    else{
        printf("%02d:%02d p.m.",hour-12, minute);
    }
}