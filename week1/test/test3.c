#include<stdio.h>

int a[100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int sum1,sum2 = 0;
    for(int i=1;i<=n;i++){
        if(i % 2 == 1){ // i为奇数
            sum1 = sum1 + a[i];
        }
        else{ // i为偶数
            sum2 = sum2 + a[i];
        }
    }

    if(sum1 > sum2){
        printf("YES");
    }
    else{
        printf("NO");
    }

}
// 10 1 2 3 4 5 6 7 8 9 10