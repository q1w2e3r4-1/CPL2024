#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[4][4];
int b[4];
int tmp[4][4];

void get(int x, int* r, int* c){
    *r = x / 3;
    *c = x % 3;
}

int check(int a, int b, int c){
    memset(tmp, 0, sizeof(tmp));

    int x1, y1, x2, y2, x3, y3;
    get(a, &x1, &y1);
    get(b, &x2, &y2);
    get(c, &x3, &y3);
    tmp[x1][y1] = tmp[x2][y2] = tmp[x3][y3] = 1;

    // shu
    for(int c=0;c<3;c++){
        int cnt = 0;
        for(int r=0;r<3;r++){
            if(tmp[r][c]) cnt ++;
        }

        if(cnt == 3) return 0;
    }

    // hang
    for(int r=0;r<3;r++){
        int cnt = 0;
        for(int c=0;c<3;c++){
            if(tmp[r][c]) cnt ++;
        }

        if(cnt == 3) return 0;
    }
    
    // xie
    int cnt = 0;
    for(int i=0;i<3;i++){
        if(tmp[i][i]) cnt ++;
    }
    if(cnt == 3) return 0;

    cnt = 0;
    for(int i=0;i<3;i++){
        if(tmp[i][3-i]) cnt ++;
    }
    if(cnt == 3) return 0;

    return 1;
}

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        scanf("%d", &b[i]);
    }

    int ans = 0;
    for (int i = 0; i < 9; i++) { // put coin 1 at position i
        for (int j = 0; j < 9; j++) { // put coin 2 at position j
            for (int k = 0; k < 9; k++) { // put coin 3 at position k
                if(i == j || i == k || j == k) continue;

                if(!check(i,j,k)) continue;
                int sum = 0;

                int x1, y1, x2, y2, x3, y3;
                get(i, &x1, &y1);
                get(j, &x2, &y2);
                get(k, &x3, &y3);
                sum += b[0] * a[x1][y1];
                sum += b[1] * a[x2][y2];
                sum += b[2] * a[x3][y3];

                if(sum > ans){
                    ans = sum;
                }
            }
        }
    }

    printf("%d\n", ans);
}