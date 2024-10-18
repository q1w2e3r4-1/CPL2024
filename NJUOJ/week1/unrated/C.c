#include<stdio.h>

int main(){
    double tmp1 = 4*atan(1.0/5);
    double tmp2 = atan(1.0 / 239);
    double pi1 = 4 * (tmp1 - tmp2);

    double tmp3 = log(pow(640320, 3) + 744);
    double tmp4 = sqrt(163);
    double pi2 = tmp3 / tmp4;
    printf("%.15lf\n%.15lf", pi1, pi2);
}