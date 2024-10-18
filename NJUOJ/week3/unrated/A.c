#include<stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    while(a && b){
        // if(a < b){
        //     int tmp = a;
        //     a = b;
        //     b = tmp;
        // }
        // printf("%d %d\n",a,b);
        int t1 = b;
        int t2 = a % b;
        a = t1;
        b = t2;
    }  

    printf("%d",a);
}