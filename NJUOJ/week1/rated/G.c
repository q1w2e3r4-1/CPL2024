#include<stdio.h>
#include<math.h>
int main(){
    double p,q;
    scanf("%lf %lf",&p, &q);
    double tmp1 = cbrt((-q/2) + sqrt(pow(q/2, 2) + pow(p/3, 3)));
    double tmp2 = cbrt((-q/2) - sqrt(pow(q/2, 2) + pow(p/3, 3)));
    // printf("%lf, %lf\n", tmp1, tmp2);
    printf("%.3lf", tmp1 + tmp2);
}