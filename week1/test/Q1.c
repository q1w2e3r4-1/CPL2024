
#include<stdio.h>

char s[105];
int main()
{   
    int a;
    long long b;
    char c;
    // char s[105];
    double d;
    scanf("%d %lld %lf%c %s",&a,&b,&d,&c,&s);
    printf("%d %d %lf %c %s",a,b,d,c,s);
}
/* input:
1234567890
12345678900000
3.1415926535
G
Hello,World!
*/


