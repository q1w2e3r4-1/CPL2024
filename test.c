#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a,b;

double F(double x){
    double ans = exp(x) - a * x * x * x - b * x - 20;
    return ans;
}

double eps = 1e-4;
int main(){
    scanf("%d %d", &a, &b);
    double l = 0, r = 100;
    while(r - l >= eps){
        // printf("%.10lf %.10lf\n",l,r);
        double mid = (l+r) / 2;
        double tmp = F(mid);

        if(tmp < 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    printf("%.10f", l);
}