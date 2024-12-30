#include<stdio.h>
int main() {
    int p1,p2;
    scanf("%d%d",&p1,&p2);
    char s[10];
    scanf("%s",s);
    int p=p2+1;
    if(p1>p2) {
        p=p1+1;
    }
    int P[p],P2[p],P1[p],J[p],C[p1+p2+1];
    for(int i=0;i<p;i++) {
        P1[i]=0;
        P2[i]=0;
    }
    for(int i=0;i<p1+p2+1;i++) {
        C[i]=0;
    }
    for(int i=p-p1-1;i<p;i++) {
        scanf("%d",&P1[p-i-1]);
    }
    for(int i=p-p2-1;i<p;i++) {
        scanf("%d",&P2[p-i-1]);
    }
    for(int i=0;i<p;i++) {
        P[i]=P1[i]+P2[i];
        J[i]=P1[i]-P2[i];
    }
    for(int i=0;i<p1+p2+1;i++) {
        for(int j=0;j<=i&&j<=p1;j++) {
            C[i]=C[i]+P1[j]*P2[i-j];
        }
    }
    int n=p-1;
    while (n+1) {
        if(P[n]==0) {
            n--;
            continue;
        }
        if(n==1) {
            if(n!=p-1) {
                if(P[n]>0) {
                    if(P[n]!=1) printf("+%d%s",P[n],s);
                    else printf("+%s",s);
                }
                else {if(P[n]!=-1) printf("%d%s",P[n],s);
                    else printf("-%s",s);
                }
            }
            else {
                if(P[n]==1) printf("%s",s);
                else if(P[n]==-1) printf("-%s",s);
                else printf("%d%s",P[n],s);
            }
            n--;
            continue;
        }
        if(n==0) {
            if(P[n]>0) {
                printf("+%d",P[n]);
            }
            else {
                printf("%d",P[n]);
            }
            break;
        }
        if(P[n]>0) {
            if(n==p-1) {
                if(P[n]!=1) {
                    printf("%d%s^%d",P[n],s,n);
                } else {
                    printf("%s^%d",s,n);
                }
            }
            else {
                if(P[n]==1) {
                    printf("+%s^%d",s,n);
                }
                else {
                    printf("+%d%s^%d",P[n],s,n);
                }
            }
        }
        if(P[n]<0) {if(P[n]!=-1) {
            printf("%d%s^%d",P[n],s,n);
        }
            else {
                printf("-%s^%d",s,n);
            }
        }
        n--;
    }
    printf("\n");
    n=p-1;
    while (n+1) {
        if(J[n]==0) {
            n--;
            continue;
        }
        if(n==0) {
            if(J[n]>0) {
                printf("+%d",J[n]);
            }
            else {
                printf("%d",J[n]);
            }
            break;
        }
        if(n==1) {
            if(n!=p-1) {
                if(J[n]>0) {
                    if(J[n]!=1) printf("+%d%s",J[n],s);
                    else printf("+%s",s);
                }
                else {if(J[n]!=-1) printf("%d%s",J[n],s);
                else printf("-%s",s);
                }
            }
            else {
                if(J[n]==1) printf("%s",s);
                else if(J[n]==-1) printf("-%s",s);
                else printf("%d%s",J[n],s);
            }
            n--;
            continue;
        }
        if(J[n]>0) {
            if(n==p-1) {
                if(J[n]!=1) {
                    printf("%d%s^%d",J[n],s,n);
                } else {
                    printf("%s^%d",s,n);
                }
            }
            else {
                if(J[n]==1) {
                    printf("+%s^%d",s,n);
                }
                else {
                    printf("+%d%s^%d",J[n],s,n);
                }
            }
        }
        if(J[n]<0) {if(J[n]!=-1) {
            printf("%d%s^%d",J[n],s,n);
        }
        else {
            printf("-%s^%d",s,n);
        }
        }
        n--;
    }
    printf("\n");
    n=p1+p2;
    while (n+1) {
        if(C[n]==0) {
            n--;
            continue;
        }
        if(n==0) {
            if(C[n]>0) {
                printf("+%d",C[n]);
            }
            else {
                printf("%d",C[n]);
            }
            break;
        }
        if(n==1) {
            if(n!=p-1) {
                if(C[n]>0) {
                    if(C[n]!=1) printf("+%d%s",C[n],s);
                    else printf("+%s",s);
                }
                else {if(C[n]!=-1) printf("%d%s",C[n],s);
                else printf("-%s",s);
                }
            }
            else {
                if(C[n]==1) printf("%s",s);
                else if(C[n]==-1) printf("-%s",s);
                else printf("%d%s",C[n],s);
            }
            n--;
            continue;
        }
        if(C[n]>0) {
            if(n==p1+p2) {
                if(C[n]!=1) {
                    printf("%d%s^%d",C[n],s,n);
                } else {
                    printf("%s^%d",s,n);
                }
            }
            else {
                if(C[n]==1) {
                    printf("+%s^%d",s,n);
                }
                else {
                    printf("+%d%s^%d",C[n],s,n);
                }
            }
        }
        if(C[n]<0) {if(C[n]!=-1) {
            printf("%d%s^%d",C[n],s,n);
        }
        else {
            printf("-%s^%d",s,n);
        }
        }
        n--;
    }
    return 0;
}