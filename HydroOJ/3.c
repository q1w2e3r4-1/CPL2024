#include<stdio.h>

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    if(x > y){
        printf("%d", (x-y)*60 + y*90);
    }
    else{
        printf("%d", (y-x)*40 + x*90);
    }
}