#include<stdio.h>

char month[30], weekday[30];
int day,year,hour,minute,second;
int main(){
    scanf("%s %d %d %s %d %d %d",month,&day,&year,weekday,&hour,&minute,&second);
    printf("%.3s %.3s %02d %02d:%02d:%02d %04d",weekday,month,day,hour,minute,second,year);
}