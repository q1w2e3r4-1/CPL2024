#include<stdio.h>

int n,m;
int board[505][505];
int d[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int pos[250005][4]; // x1, y1, x2, y2

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &board[i][j]);
        }
    }

    int num = n*m / 2;
    for(int i=1;i<=num;i++){
        for(int j=0;j<4;j++){
            pos[i][j] = -1;
        }
    }

    // 1. find pos
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x = board[i][j];
            if(pos[x][0] == -1 && pos[x][1] == -1){
                pos[x][0] = i, pos[x][1] = j;
            }
            else{
                pos[x][2] = i, pos[x][3] = j;
            }
        }
    }

    for(int x=1; x<=num; x++){
        int x1 = pos[x][0], y1 = pos[x][1];
        int x2 = pos[x][2], y2 = pos[x][3];
        // 2.check
        int ok = 0;
        for(int z=0;z<4;z++){
            int ok1 = 1, ok2 = 1;
            // printf("haha%d\n", x);
            // check(x1, y1)
            int x0 = x1, y0 = y1;
            while(1){
                x0 = x0 + d[z][0];
                y0 = y0 + d[z][1];
                
                if(x0 < 1 || x0 > n || y0 < 1 || y0 > m){
                    break;
                }

                if(board[x0][y0] != 0){
                    ok1 = 0;
                    break;
                }
            }

            // check(x2, y2)
            x0 = x2, y0 = y2;
            while(1){
                x0 = x0 + d[z][0];
                y0 = y0 + d[z][1];
                
                if(x0 < 1 || x0 > n || y0 < 1 || y0 > m){
                    break;
                }

                if(board[x0][y0] != 0){
                    ok1 = 0;
                    break;
                }
            }
            
            if(ok1 && ok2){
                ok = 1;
            }
        }

        // 3.print result
        if(ok){
            printf("%d ", x);
            board[x1][y1] = board[x2][y2] = 0;
        }
    }
}