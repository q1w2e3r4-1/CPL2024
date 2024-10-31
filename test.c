#include<stdio.h>
#include<stdlib.h>

int a[10][15];
int n,m;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &a[i][j]);
        }
    }    

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }  
}

/*
3 2

1 2
3 4
5 6
*/