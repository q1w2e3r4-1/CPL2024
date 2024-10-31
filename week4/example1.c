#include<stdio.h>

//T组数据，每组数据要求你找出数组中的所有偶数，并把它倒着打印出来

int a[105],is_even[105];
int n,T;

int main(){
    scanf("%d",&n);

    // for(int i=n-1;i>=0;i--){
    //     printf("%d ",is_even[i]);
    // }
    // printf("\n");
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

        if(a[i] % 2 == 0){
            is_even[i] = 1; // true 
        }
    }

    for(int i=n-1;i>=0;i--){
        if(is_even[i]){
            printf("%d ",a[i]);
        }
    }

    printf("\n");
}

/*
3
5
1 2 3 4 5
5 
4 5 4 5 4
5
1 3 5 7 9
*/
