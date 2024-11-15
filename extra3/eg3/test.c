#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int Xa=0,Ya=0,Xb=0,Yb=0,Xc=0,Yc=0,dist=0;
    scanf("%d %d",&Xa,&Ya);
    scanf("%d %d",&Xb,&Yb);
    scanf("%d %d",&Xc,&Yc);
    dist=abs(Xa-Xb)+abs(Ya-Yb);
    if(Xa==Xb&&Xb==Xc&&1LL*(Ya-Yc)*(Yb-Yc)<=0) {
        printf("%d\n",dist+2);
    }else if(Ya==Yb&&Yb==Yc&&1LL*(Xa-Xc)*(Xb-Xc)<=0) {
        printf("%d\n",dist+2);
    }else {
        printf("%d\n",dist);
    }
    return 0;
    int dx=Xb-Xa;
    int dy=Yb-Ya;
    if(Xa==Xb&&Xb==Xc&&(Ya-Yc)*(Yb-Yc)<0) {
        printf("L");
        if(dy>0) {
            for(int i=1;i<=dy;i++) {
                printf("U");
            }
        }else {
            for(int i=-1;i>=dy;i--) {
                printf("D");
            }
        }
        printf("R");
    }else if(Ya==Yb&&Yb==Yc&&(Xa-Xc)*(Xb-Xc)<0) {
        printf("U");
        if(dx>0) {
            for(int i=1;i<=dx;i++) {
                printf("R");
            }
        }else {
            for(int i=-1;i>=dx;i--) {
                printf("L");
            }
        }
        printf("D");
    }else if((Ya-Yc)*(Yb-Yc)>0|(Xa-Xc)*(Xb-Xc)>0){
        if(dx>0) {
            for(int i=1;i<=dx;i++) {
                printf("R");
            }
        }else {
            for(int i=-1;i>=dx;i--) {
                printf("L");
            }
        }
        if(dy>0) {
            for(int i=1;i<=dy;i++) {
                printf("U");
            }
        }else {
            for(int i=-1;i>=dy;i--) {
                printf("D");
            }
        }
    }else {
        if(Xc!=Xb&&Yc!=Ya){
            if(dx>0) {
                for(int i=1;i<=dx;i++) {
                    printf("R");
                }
            }else {
                for(int i=-1;i>=dx;i--) {
                    printf("L");
                }
            }
            if(dy>0) {
                for(int i=1;i<=dy;i++) {
                    printf("U");
                }
            }else {
                for(int i=-1;i>=dy;i--) {
                    printf("D");
                }
            }
        }else {
            if(dy>0) {
                for(int i=1;i<=dy;i++) {
                    printf("U");
                }
            }else {
                for(int i=-1;i>=dy;i--) {
                    printf("D");
                }
            }
            if(dx>0) {
                for(int i=1;i<=dx;i++) {
                    printf("R");
                }
            }else {
                for(int i=-1;i>=dx;i--) {
                    printf("L");
                }
            }
        }
    }
    return 0;
}