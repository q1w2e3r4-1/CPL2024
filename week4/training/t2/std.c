#include<stdio.h>

int a[105];
int n;

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }    

    int mx = -2e9;
    int mx_idx = -1;
    for(int i=0;i<n;i++){
        if(a[i] >= mx){
            mx = a[i];
            mx_idx = i;
        }
    }

    printf("%d %d", mx, mx_idx);
}