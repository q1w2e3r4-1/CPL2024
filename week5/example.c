#include<stdio.h>

int n,a[15];

void func(){
    printf("haha\n");
}

int max(int a, int b){
    func();
    printf("MAXXXXX\n");
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    func();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }

    int mx = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx, a[i]);
    }

    printf("%d\n", mx);
}

// 10 5 7 1 6 10 4 2 9 8 3