#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    char m[1001],n[1001],k[1002];

    int i=0,j=0,max=0,x=0;
    scanf("%s%s", m,n);
    for (int w = 0; w < 1001; w++) {
        k[w]='0';
    }
    i=strlen(m);
    j=strlen(n);
    if(i==1&&m[0]==0) {
        if(j==1&&n[0]==0) {
            printf("0\n");
            return 0;
        }
        for (int w = 0; w < j; w++) {
            printf("%c",n[w]);
        }
    }
    if(j==1&&n[0]==0) {
        for (int w = 0; w < i; w++) {
            printf("%c",m[w]);
        }
    }
    for (int w = i; w < 1000; w++) {
        m[w]='0';
    }
    for (int w = j; w < 1000; w++) {
        n[w]='0';
    }
    for (int w = 0; w < i/ 2; w++) {
        char temp=m[w];
        m[w]=m[i-w-1];
        m[i-w-1]=temp;
    }
    for (int w = 0; w < j/ 2; w++) {
        char temp=n[w];
        n[w]=n[j-w-1];
        n[j-w-1]=temp;
    }
    max=i>j?i:j;
    for (int w = 0; w < max; w++) {
            k[w]=(char)((int)m[w]+(int)n[w]-48);
        if (k[w]>57) {
            k[w]=(char)((int)k[w]-10);
            m[w+1]=(char)((int)m[w+1]+1);
        }
    }
    if ((int)k[max]!=48) {
        for (int w = max; w >=0; w--) {
            printf("%c",k[w]);
        }
    } else {
        for (int w = max-1; w >=0; w--) {
            printf("%c",k[w]);
        }
    }
    printf("\n");
    return 0;
}