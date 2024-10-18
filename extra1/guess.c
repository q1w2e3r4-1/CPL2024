#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int target = rand() % 100 + 1;

    int l=1, r=100;
    int x;
    int cnt = 0;
    while(1){
        cnt ++;
        printf("Enter a number between %d - %d: ",l,r);
        scanf("%d",&x);
        if(x == target){
            printf("You guess right, with %d attempt\n", cnt);
            break;
        }
        else if(x > target){
            printf("too high, try again\n");
            r = x - 1;
        }
        else{
            printf("too low, try again\n");
            l = x + 1;
        }
    }
}