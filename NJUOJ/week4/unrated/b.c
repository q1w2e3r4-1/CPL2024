#include<stdio.h>

double a[10][10];
double b[5][5];

double cal(){
    double t1 = b[1][1] * (b[2][2] * b[3][3] - b[2][3] * b[3][2]);
    double t2 = b[1][2] * (b[2][1] * b[3][3] - b[2][3] * b[3][1]);
    double t3 = b[1][3] * (b[2][1] * b[3][2] - b[2][2] * b[3][1]);
    return t1 - t2 + t3;
}

int main(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=4;j++){
            scanf("%lf", &a[i][j]);
        }
    }

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            b[i][j] = a[i][j];
        }
    }
    double d0 = cal();

    for(int i=1;i<=3;i++){
        b[i][1] = a[i][4];
    }
    double dx = cal();

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            b[i][j] = a[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        b[i][2] = a[i][4];
    }
    double dy = cal();

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            b[i][j] = a[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        b[i][3] = a[i][4];
    }
    double dz = cal();

       printf("%.2lf %.2lf %.2lf", dx / d0, dy / d0, dz/ d0);
}