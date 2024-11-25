#include<stdio.h>

int T, a,b,c;

char ans[105][105];

void test(int row, int col){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}

void heng(int row, int col){
    for(int x=2*b+1; x<=row; x+=2){
        for(int y=1;y<=2*a+1; y++){
            if(y % 2 == 1){
                ans[x][y] = '+';
            }
            else{
                ans[x][y] = '-';
            }
        }
    }

    for(int x = 2*b + 1; x >= 1; x -= 2){
        int start = 2*b + 2 - x;
        int end = start + 2*a;
        for(int y=start; y<=end; y++){
            if(y % 2 == 1){
                ans[x][y] = '+';
            }
            else{
                ans[x][y] = '-';
            }
        }
    }
}

void shu(int row, int col){
    for(int x=2*b+2; x<=row; x+=2){
        int start = 1;
        int end = 1 + 2 * a;

        for(int y=start; y<=end; y+= 2){
            ans[x][y] = '|';
        }
    }

    int x0 = 2*b + 1, y0 = 2*a + 1;
    for(int z=0; z<=b; z++){
        int start = x0;
        int end = x0 + c * 2;
        for(int x=start; x<=end;x++){
            if(x % 2 == 1){
                ans[x][y0] = '+';
            }
            else{
                ans[x][y0] = '|';
            }
        }

        x0 -= 2;
        y0 += 2;
    }
}

void xie(int row, int col){
    int x0 = 2*b+1, y0 = 1;
    for(int z=0;z<=a;z++){

        int x = x0, y = y0;
        for(int i=0;i<=2*b;i++){
            if(i % 2 == 0){
                ans[x][y] = '+';
            }
            else{
                ans[x][y] = '/';
            }

            x --;
            y ++;
        }
        
        y0 += 2;
    }

    x0 = 2*b+1, y0 = 2*a+1;
    for(int z=0;z<=c;z++){
        int x = x0, y = y0;
        for(int i=0;i<=2*b;i++){
            if(i % 2 == 0){
                ans[x][y] = '+';
            }
            else{
                ans[x][y] = '/';
            }

            x --;
            y ++;
        }
        
        x0 += 2;
    }
}


int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &a, &b, &c);
        int row = (b + c) * 2 + 1;
        int col = (a + b) * 2 + 1;

        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                ans[i][j] = ' ';
            }
        }

        heng(row, col);
        shu(row, col);
        xie(row, col);
        test(row, col);
    }
}