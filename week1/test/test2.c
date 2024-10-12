#include<stdio.h>

int a[1005],n;

int main(){
    int a[1000005];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }    

    int max = 0;
    for(int i=0;i<n;i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    printf("max = %d\n",max);
}

// test1:
// 10 10 9 8 7 6 5 4 3 2 1
// test2:
// 5 -1 -2 -3 -4 -5
// test3:
// 5 1 2 3 4 5