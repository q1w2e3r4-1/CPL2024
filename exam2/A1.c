#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[4][4];
int b[4];

void get(int x, int *a, int *b){
    *a = x / 3 + 1;
    *b = x % 3 + 1;
}

int s[4][4];
int check(){
    for(int i=1;i<=3;i++){
        int cnt = 0;
        for(int j=1;j<=3;j++) cnt += s[i][j];
        if(cnt == 3) return 0;
    }

    for(int i=1;i<=3;i++){
        int cnt = 0;
        for(int j=1;j<=3;j++) cnt += s[j][i];
        if(cnt == 3) return 0;
    }

    int cnt = 0;
    for(int i=1;i<=3;i++){
        cnt += s[i][i];
    }
    if(cnt == 3) return 0;

    cnt = 0;
    for(int i=1;i<=3;i++){
        cnt += s[i][4-i];
    }
    if(cnt == 3) return 0;
    return 1;
}

int main(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=1;i<=3;i++){
        scanf("%d", &b[i]);
    }

    int ans = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                memset(s, 0, sizeof(s));
                if(i == j || i == k || j == k) continue;
                int x1, y1, x2, y2, x3, y3;
                get(i, &x1, &y1);
                get(j, &x2, &y2);
                get(k, &x3, &y3);
                s[x1][y1] = s[x2][y2] = s[x3][y3] = 1;

                if(!check()) continue;
                int sum = 0;
                sum += a[x1][y1] * b[1];
                sum += a[x2][y2] * b[2];
                sum += a[x3][y3] * b[3];
                if(sum > ans){
                    // printf("%d %d %d %d %d %d %d\n", x1,y1,x2,y2,x3,y3, sum);
                    ans = sum;
                }
            }
        }
    }

    printf("%d", ans);
}