#include<stdio.h>

char s[105];
char t[105];
int a,b=99999;
char c;

int main(){
    scanf("%s",s);
    printf("%s\n",s);

    scanf("%s %s",s,t);
    printf("%s%s\n",s,t);

    scanf("%d %s",&a,s);
    printf("%s\n",s);

    scanf("%d",&a);
    c = getchar(); printf("%c",c);
    c = getchar(); printf("%c",c);
    c = getchar(); printf("%c",c);
    c = getchar();
    c = getchar();
    printf("\n");

    c = getchar();
    c = getchar(); printf("%c",c);
    c = getchar();
    c = getchar(); printf("%c",c);
    c = getchar();
    c = getchar(); printf("%c",c);
    c = getchar();
    c = getchar(); printf("%c",c);
    c = getchar();
    printf("\n");

    scanf("%s", s);
    printf("%.8s\n",s);
}

/*
abcdefg
abc def
1234efg
12abc34
q1w2e3r4
congrats!!
*/