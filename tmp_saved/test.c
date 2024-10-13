#include<stdio.h>

char s[105], t[105];
int main()
{
    scanf("%s", s);
    printf("%s\n", s);

    scanf("%s %s", s, t);
    printf("%s%s\n",s,t);

    int a;
    scanf("%d %s", &a, s);
    printf("%s\n", s);

    char c;
    scanf("%d", &a);
    c = getchar(); putchar(c);
    c = getchar(); putchar(c);
    c = getchar(); putchar(c);
    c = getchar();
    c = getchar();
    printf("\n");

    c = getchar();
    c = getchar(); putchar(c);
    c = getchar();
    c = getchar(); putchar(c);
    c = getchar();
    c = getchar(); putchar(c);
    c = getchar();
    c = getchar(); putchar(c);
    c = getchar();
    printf("\n");

    scanf("%s", s);
    printf("%.7s\n", s);
}
/* input:
abcdefg
abc def
1234efg
12abc34
q1w2e3r4
congrats!!
*/