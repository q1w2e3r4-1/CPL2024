#include<stdio.h>

int n,p[2005];
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &p[i]);

    // step1
    int idx = n;
    for(int i=n-1;i>=1;i--){
        if(p[i] > p[i+1]){
            idx = i;
        }
        else{
            break;
        }
    }

    int k = p[idx-1];

    int r;
    for(int i=n;i>=idx;i--){
        if(p[i] > k){
            r = i;
            break;
        }
    }

    // swap idx and r
    int tmp = p[idx-1];
    p[idx-1] = p[r];
    p[r] = tmp;

    // reverse p[idx: n]
    int L = idx, R = n;
    while(L < R){
        // swap L & R
        int tmp = p[L];
        p[L] = p[R];
        p[R] = tmp;
        L ++;
        R --;
    }


    for(int i=1;i<=n;i++){
        printf("%d ", p[i]);
    }
}