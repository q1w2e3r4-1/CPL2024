#include<stdio.h>
int n,m,t,a[1000005],b[1000005];

int min(int x, int y){
    if(x < y) return x;
    return y;
}

int main(){
    scanf("%d %d %d", &n, &m, &t);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=m;i++) scanf("%d", &b[i]);

    int mn = 2e9 + 5;
    for(int j=1;j<=m;j++){
        int target = t - b[j];
        // 最后一个小于等于target的数

        int l = 1, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(a[mid] <= target){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }

        if(a[l] + b[j] <= t){
            mn = min(mn, t - (a[l] + b[j]));
        }
    }
    if(mn == 2e9 + 5){
        printf("-1");
    }
    else{
        printf("%d", mn);
    }
}