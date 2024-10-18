#include<stdio.h>

int n,k;
int a[1000005];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }    

    int pivot = a[k];
    int l=1, r=n;
    while(l != r){
        while(l != r && a[l] < pivot){
            l++;
        }
        while(l != r && a[r] >= pivot){
            r--;
        }
        if(l != r){
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
    }

    for(int i=1;i<=n;i++){
        if(a[i] == pivot){
            k = i;
            break;
        }
    }

    if(a[l] > a[k]){
        int tmp = a[l];;
        a[l] = a[k];
        a[k] = tmp;
    }
    
    for(int i=1;i<=n;i++){
        printf("%d ", a[i]);
    }
}