#include<stdio.h>

int n,q,target;
char tmp[4];
int L = 1, R = 2;

int shun(int x){
    x ++;
    if(x > n) x -= n;
    return x;
}

int ni(int x){
    x --;
    if(x == 0) x += n;
    return x;
}

int R_shun(int l, int r, int target){
    int cnt = 0;
    while(r != target){
        r = shun(r);
        cnt ++;
        if(l == r) return -1;
    }
    return cnt;
}   

int R_ni(int l, int r, int target){
    int cnt = 0;
    while(r != target){
        r = ni(r);
        cnt ++;
        if(l == r) return -1;
    }
    return cnt;
}   

int L_shun(int l, int r, int target){
    int cnt = 0;
    while(l != target){
        l = shun(l);
        cnt ++;
        if(l == r) return -1;
    }
    return cnt;
}   

int L_ni(int l, int r, int target){
    int cnt = 0;
    while(l != target){
        l = ni(l);
        cnt ++;
        if(l == r) return -1;
    }
    return cnt;
}   

int main(){
    scanf("%d %d", &n, &q);
    long long ans = 0;

    while(q--){
        scanf("%s %d", tmp, &target);
        if(tmp[0] == 'L'){
            // move left
            int x = L_shun(L, R, target);
            int y = L_ni(L, R, target);
            if(x == -1) ans += y;
            else ans += x;

            L = target;
        }
        else{
            // tmp[1] == 'R'
            int x = R_shun(L, R, target);
            int y = R_ni(L, R, target);
            if(x == -1) ans += y;
            else ans += x;
            
            R = target;
        }
    }

    printf("%lld", ans);
}