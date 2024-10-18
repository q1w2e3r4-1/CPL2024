#include<stdio.h>

int last_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int month, day;
    scanf("%d %d",&month, &day);
    if(day == last_day[month]){
        day = 1;
        month ++;
        if(month > 12) month = 1;
    }
    else{
        day ++;
    }

    printf("%d %d", month, day);
}