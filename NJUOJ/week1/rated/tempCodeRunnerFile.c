#include<stdio.h>

int main(){
    char s[30];
    int pre;
    double frac,factor;
    char unit;

    scanf("%s %d %lf %lf %c",s, &pre, &frac,&factor, &unit);

    double sciEexp = pre + frac;
    double conv = sciEexp * factor;
    unit = unit - 'a' + 'A';
    printf("%.2s: %d (%.5lf) | %.5E %.5lf %c",s, pre, frac, sciEexp, conv, unit);    
}