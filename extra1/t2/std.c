#include<stdio.h>
#include<math.h>

int a,b;

// F(x) = e^{x}-ax^{3}-bx-20
double F(double x){
    double ans = exp(x) - a * x * x * x - b * x - 20;
    return ans;        
}

const double eps = 1e-10;
int main(){
    scanf("%d %d",&a, &b);
    double l = 0.0, r = 1e8;
    while((r - l) > eps){
        // printf("%.10lf, %.10lf\n", l, r);
        double mid = (l + r) / 2;
        if(F(mid) < 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    printf("%.10lf",l);
}
