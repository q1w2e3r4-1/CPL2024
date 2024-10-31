#include<stdio.h>

int main(){
    int a = -1;
    int b[5] = {1,2,3,4,5};
    int c = 6;

    b[7] = 100;
    printf("%d %d\n",a, c);
    printf("%p,%p,%p",&a,b+7,&c);
}

