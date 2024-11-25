#include<stdio.h>

int p, q, r;

int convert(int x, int B){
    int shi = x / 10;
    int ge = x % 10;
    if(ge >= B || shi >= B) return -1;
    return shi * B + ge;
}

int check(int p, int q, int r, int B){
    int x = convert(p, B);
    int y = convert(q, B);
    int z = convert(r, B);

    if(x == -1 || y == -1 || z == -1) return 0;
    if(x * y == z) return 1;
    return 0;
}

int main(){
    scanf("%d %d %d", &p, &q, &r);
    for(int B=2;B<=40;B++){
        if(check(p, q, r, B)){
            printf("%d", B);
            return 0;
        }
    }

    printf("0");
}