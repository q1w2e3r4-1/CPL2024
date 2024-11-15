#include<stdio.h>

void move_x(int x1, int x2){
    if(x1 < x2){
        while(x1 < x2){
            printf("R");
            x1 ++;
        }
    }
    else{
        while(x1 > x2){
            printf("L");
            x1 --;
        }
    }
}

void move_y(int y1, int y2){
    if(y1 < y2){
        while(y1 < y2){
            printf("U");
            y1 ++;
        }
    }
    else{
        while(y1 > y2){
            printf("D");
            y1 --;
        }
    }
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    
    int dist = 0;
    if(x2 > x1) dist += x2 - x1;
    else{
        dist += x1 - x2;
    }

    if(y2 > y1){
        dist += y2 - y1;
    }
    else{
        dist += y1 - y2;
    }

    if(x1 == x2 || y1 == y2){
        // AB共线
        if(x1 == x2){
            if(x1 == x3 && 1LL * (y3 - y1)  * (y3 - y2) < 0){
                // C挡住AB
                printf("%d\n", dist + 2);
                // printf("R");
                // move_y(y1, y2);
                // printf("L");
            }
            else{
                printf("%d\n", dist);
                // move_y(y1, y2);
            }
        }
        else{
            if(y1 == y3 && 1LL * (x3 - x1) * (x3 - x2) < 0){
                // C挡住AB
                printf("%d\n", dist + 2);
                // printf("U");
                // move_x(x1, x2);
                // printf("D");
            }
            else{
                printf("%d\n", dist);
                // move_x(x1,x2);
            }
        }
    }
    else{
        printf("%d\n", dist);
        int x4 = x2;
        int y4 = y1;
        // ((x1, y1) - (x4, y4))
        int blocked = 0;
        if(y1 == y3 && 1LL * (x1 - x3) * (x4 - x3) <= 0){
            blocked = 1;
        }
        if(x2 == x3 && 1LL * (y2 - y3) * (y4 - y3) <= 0){
            blocked = 1;
        }

        // if(blocked){
        //     move_y(y1, y2);
        //     move_x(x1, x2);
        // }
        // else{
        //     move_x(x1, x2);
        //     move_y(y1, y2);
        // }
    }
}