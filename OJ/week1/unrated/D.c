#include<stdio.h>

int main(){
    const double G = 6.674e-11;
    const double M = 77.15;
    double m,r;
    scanf("%lf %lf",&m,&r);
    printf("%.3e", G*M*m/r/r);
}