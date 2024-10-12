#include<stdio.h>
char month[20], weekday[20];
int day,year,h,m,s;

int main(){
    scanf("%s %d %d %s %d %d %d",month,&day,&year,weekday,&h,&m,&s);
    printf("%.3s %.3s %02d %02d:%02d:%02d %04d",weekday, month, day,h,m,s,year);
}