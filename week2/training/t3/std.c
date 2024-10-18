#include<stdio.h>

int main(){
    int last_day = 0;

    int month, day;
    scanf("%d %d",&month, &day);
    switch(month){
        case 1: last_day = (day == 31); break;
        case 2: last_day = (day == 28); break;
        case 3: last_day = (day == 31); break;
        case 4: last_day = (day == 30); break;
        case 5: last_day = (day == 31); break;
        case 6: last_day = (day == 30); break;
        case 7: last_day = (day == 31); break;
        case 8: last_day = (day == 31); break;
        case 9: last_day = (day == 30); break;
        case 10: last_day = (day == 31); break;
        case 11: last_day = (day == 30); break;
        case 12: last_day = (day == 31); break;
    }

    if(last_day){
        month ++;
        if(month == 13){
            month = 1;
        }
        day = 1;
    }
    else{
        month = month;
        day ++;
    }

    printf("%d %d", month, day);
}