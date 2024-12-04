#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int x;
    int y;
}Tile;

Tile ans[1000005];
int tot = 0;
int k;

char s[2005][2005];

void solve(int x, int y, int nx, int ny, int k){
    // 右上1， 右下2， 左上3,  左下4
    int type = 0;
    int half = 1 << (k-1);
    if(nx < x + half && ny < y + half){
        type = 3;
    }else if(nx < x + half && ny >= y + half){
        type = 1;
    }else if(nx >= x + half && ny < y + half){
        type = 4;
    }else{
        type = 2;
    }

    if(k == 1){
        if(type == 1){
            ans[++tot].id = 1;
            ans[tot].x = x+1;
            ans[tot].y = y;
        }
        else if(type == 2){
            ans[++tot].id = 2;
            ans[tot].x = x;
            ans[tot].y = y;
        }
        else if(type == 3){
            ans[++tot].id = 3;
            ans[tot].x = x+1;
            ans[tot].y = y+1;
        }
        else{
            ans[++tot].id = 4;
            ans[tot].x = x;
            ans[tot].y = y+1;
        }
        return;
    }
    
    if(type == 1){
        ans[++tot].id = 1;
        ans[tot].x = x+half;
        ans[tot].y = y+half-1;
        solve(x, y, x+half-1, y+half-1, k-1);
        solve(x, y+half, nx, ny, k-1);
        solve(x+half, y, x+half, y+half-1, k-1);
        solve(x+half, y+half, x+half, y+half, k-1);
    }
    else if(type == 2){
        ans[++tot].id = 2;
        ans[tot].x = x+half-1;
        ans[tot].y = y+half-1;
        solve(x, y, x+half-1, y+half-1, k-1);
        solve(x, y+half, x+half-1, y+half, k-1);
        solve(x+half, y, x+half, y+half-1, k-1);
        solve(x+half, y+half, nx,ny, k-1);
    }
    else if(type == 3){
        ans[++tot].id = 3;
        ans[tot].x = x+half;
        ans[tot].y = y+half;
        solve(x, y, nx, ny, k-1);
        solve(x, y+half, x+half-1, y+half, k-1);
        solve(x+half, y, x+half, y+half-1, k-1);
        solve(x+half, y+half, x+half, y+half, k-1);
    }
    else{
        ans[++tot].id = 4;
        ans[tot].x = x+half-1;
        ans[tot].y = y+half;
        solve(x, y, x+half-1, y+half-1, k-1);
        solve(x, y+half, x+half-1, y+half, k-1);
        solve(x+half, y, nx, ny, k-1);
        solve(x+half, y+half, x+half, y+half, k-1);
    }
}

// 右上1， 右下2， 左上3,  左下4
int d[4][3][2] = {
    {{0,0}, {-1,0}, {0,1}},
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {-1,0}, {0,-1}},
    {{0,0}, {1,0}, {0,-1}}
};

void check(){
    // tot表示你的答案，ans[1]~ans[tot]表示你的答案
    for(int i=1;i<=tot;i++){
        int x = ans[i].x, y = ans[i].y, type = ans[i].id;
        for(int z=0;z<3;z++){
            int nx = x + d[type-1][z][0];
            int ny = y + d[type-1][z][1];
            // 如果你想判越界就打开下面的注释
            // if(nx < 0 || nx >= (1<<k) || ny < 0 || ny >= (1<<k)){
            //     printf("error\n");
            //     exit(0);
            // }
            // if(s[nx][ny] == 'X'){
            //     printf("error\n");
            //     exit(0);
            // }
            s[nx][ny] = type + '0';
        }
    }
    for(int i=0;i<(1<<k);i++){
       printf("%s\n", s[i]);
    }
}

int main(){
    scanf("%d", &k);
    int nx,ny;
    for(int i=0;i<(1<<k);i++){
        scanf("%s", s[i]);
        for(int j=0;j<(1<<k);j++){
            if(s[i][j] == 'X'){
                nx = i;
                ny = j;
            }
        }
    }
    solve(0,0,nx,ny,k);
    // check();
    printf("%d\n", tot);
    for(int i=1;i<=tot;i++){
        printf("%d %d %d\n", ans[i].id, ans[i].x+1, ans[i].y+1);
    }
}

/*
1
..
.X

1
..
X.
*/