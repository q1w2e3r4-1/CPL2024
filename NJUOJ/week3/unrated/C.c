#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&m,&n);

    int start_col = 0;
    if(n != 1){
        start_col = n - 1;
    }
    else{
        start_col = 7;
    }
    
    for(int i=1;i<start_col;i++){
        printf("    ");
    }

    for(int i=1;i<=m;i++){
        printf("%2d  ", i);
        start_col ++;

        if(start_col > 7){
            start_col = 1;
            printf("\n");
        }
    }
}