#include<stdio.h>

int vis[55][55];
char mp[55][55];
int n,m,x,y;
int tot = 0;
int ans[2505][2];

int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(){    
    scanf("%d%d%d%d", &n, &m, &x, &y);
    x--; y--;
    for(int i=0;i<n;i++){
        scanf("%s", mp[i]);
    }

    while(1){
        // printf("%d %d\n", x+1,y+1);
        ans[tot][0] = x+1;
        ans[tot][1] = y+1;
        tot ++;

        vis[x][y] = 1;
        int find = 0;
        for(int i=0;i<4;i++){
            int x1 = x + d[i][0];
            int y1 = y + d[i][1];
            if(x1 < 0 || x1 >= n) continue;
            if(y1 < 0 || y1 >= m) continue;
            if(mp[x1][y1] == '#' && !vis[x1][y1]){
                x = x1;
                y = y1;
                find = 1;
                break;
            }
        }

        if(!find){
            break;
        }
    }

    printf("%d\n",tot);
    for(int i=0;i<tot;i++){
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
}