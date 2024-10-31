#include<stdio.h>

int n;
char s[100005];
int a[100005];
int tot = 0;

int reverse(int x){
    return x % 10 * 10 + x / 10;
}

int main(){
    scanf("%d%s",&n, s);
    for(int i=0;i<n/2;i++){
        if(s[i] == '?' && s[n-i-1] == '?'){
            a[i] = tot;
            a[n-i-1] = reverse(tot);
            tot ++;
        }
        else if(s[i] == '?'){
            s[i] = s[n-i-1];
        }
        else if(s[n-i-1] == '?'){
            s[n-i-1] = s[i];
        }
    }

    for(int i=0;i<n;i++){
        if(s[i] == '?'){
            printf("%02d", a[i]);
        }
        else{
            printf("%c", s[i]);
        }
    }
}