#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;
char s[20000000];
int main(){
    FILE* file = freopen("1.in", "r", stdin);
    int x1,x2,x3,y1,y2,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    // printf("%d %d %d %d %d %d", x1,y1,x2,y2,x3,y3);
    fclose(file);

    file = freopen("1.out", "r", stdin);
    scanf("%d %s", &n, s);
    for(int i=0;i<n;i++){
        switch(s[i]){
            case 'R': x1++; break;
            case 'L': x1--; break;
            case 'U': y1++; break;
            case 'D': y1--; break;
        }

        if(x1 == x3 && y1 == y3){
            return 1;
        }
    }

    if(x1 != x2 || y1 != y2){
        return 1;
    }

    printf("haha\n");
    return 0;
}