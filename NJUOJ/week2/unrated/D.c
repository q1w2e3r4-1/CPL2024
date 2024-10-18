#include<stdio.h>
#include <math.h>

int main(){
    // int n,m;
    int n;
    scanf("%d",&n);
    int m = 0;
    
    int tmp = n;
    for(int i=0;i<20;i++){
        if(tmp == 0){
            break;
        }
        else{
            m ++;
            tmp /= 10;
        }
    }

    tmp = n;
    int sum = 0;
    for(int i=0;i<20;i++){
        if(tmp == 0){
            break;
        }
        else{
            int mul = 1;
            for(int i=1;i<=m;i++){
                mul *= tmp % 10;
            }
            sum += mul;
            tmp /= 10;
        }
    }
    // printf("%d %d\n", m, sum);

    if(n == sum){
        printf("%d",m);
    }
    else{
        printf("0");
    }
}