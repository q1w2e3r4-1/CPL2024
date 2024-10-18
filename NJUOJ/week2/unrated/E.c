#include<stdio.h>
#include<math.h>

int main(){
    double x;
    int n;
    scanf("%lf %d", &x, &n);

    double ans = 0;
    int p1 = 1;
    double p2 = x;
    for(int i=0;i<=n;i++){
        double tmp = 1.0 * p1 * p2;
        tmp /= (2*i+1);
        ans += tmp;

        p1 *= -1;
        p2 *= x * x;
    }    

    printf("%.10lf", 4*ans);
}