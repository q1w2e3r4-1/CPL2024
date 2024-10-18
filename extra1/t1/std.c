#include<stdio.h>

int n,m;
int a[1000005];
int main(){
    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }

    for(int i=1;i<=m;i++){
        int target;
        scanf("%d", &target);

        int l=1, r = n;
        while(l < r){
            // printf("%d %d\n", l, r);
            int mid = (l+ r) / 2;
            int x = a[mid];

            if(x <= target){
                l = mid + 1;
            }
            else if(x > target){
                r = mid - 1;
            }
        }

        if(a[l] == target){
            printf("%d ", l);
        }
        else{
            printf("-1 ");
        }
    }
}