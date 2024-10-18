#include<stdio.h>
#include<stdlib.h>
const int MAX = 8192;
int get_rand(){
    return rand() % MAX;
}

int main(){
    srand(time(0));

    int times = 10000000;
    int cnt = 0;
    for(int i=1;i<=times;i++){
        int rd = get_rand() - MAX / 2;
        double x = 1.0 * rd / (MAX / 2);

        rd = get_rand() - MAX / 2;
        double y = 1.0 * rd / (MAX / 2);
        
        if(x*x + y*y <= 1.0){
            cnt ++;
        }
    }

    printf("%.2lf", 1.0 * cnt / times * 4);

}