#include<stdio.h>
#define int long long
int n,R,m,target;
int d[1000005];

int check(int L){
    int cnt = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(d[i] <= L || d[i] >= R) continue;
        cnt ++;
        sum += d[i] - L;
    }

    if(cnt < m) return 0;
    if(sum < target) return 0;
    return 1;
}

signed main(){
    scanf("%lld %lld %lld %lld", &n, &R, &m, &target);
    for(int i=1;i<=n;i++) scanf("%lld", &d[i]);  

    int l = 0, r = R-1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }

    if(!check(l)){
        printf("-1");
    }
    else{
        printf("%lld", l);
    }
}