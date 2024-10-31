#include<stdio.h>

int n,m;
int a[105][105], b[105][105];

int main(){
    scanf("%d %d", &n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &a[i][j]);
        }
    }   

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &b[i][j]);
        }
    }  

    int sum = n * m;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == b[i][j]){
                cnt ++;
            }
            else{

            }
        }
    }  

    double ans = 100.0 * cnt / sum;
    printf("%.2lf", ans);
}