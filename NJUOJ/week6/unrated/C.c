#include<stdio.h>

int a,b,c,x=0,y=0,z=0;
char comm[1005];

void W(){
    x -= c;

    int tmp = a;
    a = c;
    c = tmp;
}

void A(){
    y -= c;

    int tmp = b;
    b = c;
    c = tmp;
}

void S(){
    x += a;

    int tmp = a;
    a = c;
    c = tmp;
}

void D(){
    y += b;
    
    int tmp = b;
    b = c;
    c = tmp;
}

int main(){
    scanf("%d%d%d%s", &a, &b, &c, comm);
    int len = 0;
    while(comm[len] != '\0') len ++;

    for(int i=0;i<len;i++){
        char c = comm[i];
        if(c == 'W') W();
        if(c == 'A') A();
        if(c == 'S') S();
        if(c == 'D') D();
        // test();
    }

    printf("%d %d %d %d", x, x+a, y, y+b);

}