#include<stdio.h>

int main() {
    int Xa,Ya,Xb,Yb,Xc,Yc;
    int x,y,min;
    int vx,vy;
    scanf("%d %d %d %d %d %d",&Xa,&Ya,&Xb,&Yb,&Xc,&Yc);
    if(Xb>=Xa) {
        x=Xb-Xa;
        vx=1;
    }else {
        x=Xa-Xb;
        vx=-1;
    }
    if(Yb>=Ya) {
        y=Yb-Ya;
        vy=1;
    }else {
        y=Ya-Yb;
        vy=-1;
    }
    min=x+y;
    if(Xa==Xb&&Xc==Xa&&
        ((Yc>Ya&&Yc<Yb)||(Yc<Ya&&Yc>Yb))){
        printf("%d\n",min+2);
        printf("L");
        while(Ya!=Yb) {
            Ya=Ya+vy;
            if(vy==1) {
                printf("U");
            }else {
                printf("D");
            }
        }
        printf("R");
    }else if(Ya==Yb&&Yc==Ya&&
        ((Xc>Xa&&Xc<Xb)||(Xc<Xa&&Xc>Xb))){
        printf("%d\n",min+2);
        printf("U");
        while(Xa!=Xb) {
            Xa=Xa+vx;
            if(vx==1) {
                printf("R");
            }else {
                printf("L");
            }
        }
        printf("D");
    }else{
        printf("%d\n",min);
        if(Yc==Yb||Xc==Xa) {
             while(Xa!=Xb) {
                Xa=Xa+vx;
                if(vx==1) {
                    printf("R");
                }else {
                    printf("L");
                }
            }
            while(Ya!=Yb) {
                Ya=Ya+vy;
                if(vy==1) {
                    printf("U");
                }else {
                    printf("D");
                }
            }
            
        }else {
           while(Ya!=Yb) {
                Ya=Ya+vy;
                if(vy==1) {
                    printf("U");
                }else {
                    printf("D");
                }
            }
            while(Xa!=Xb) {
                Xa=Xa+vx;
                if(vx==1) {
                    printf("R");
                }else {
                    printf("L");
                }
            }
        }
    }
}