#include<stdio.h>

long long n;

static char *ones[] = {
  "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen",
  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
  "0", "1", "twenty", "thirty", "forty", 
  "fifty", "sixty", "seventy", "eighty", "ninety"};

long long f(long long x){
    long long a = x / 100;
    long long b = x / 10 % 10;
    long long c = x % 10;

    if(a != 0){
        if(b == 0 && c == 0){
            printf("%s hundred", ones[a]);
            return 0;
        }
        else{
            printf("%s hundred and ", ones[a]);
        }
    }

    if(b >= 2){
        if(c == 0){
            printf("%s", tens[b]);
        }
        else{
            printf("%s-%s", tens[b], ones[c]);
        }
    }
    else{
        long long tmp = b * 10 + c;
        printf("%s", ones[tmp]);
    }
}

int main(){
    scanf("%lld", &n);
    if(n == 0){
        printf("zero");
        return 0;
    }
    
    if(n < 0){
        printf("minus ");
        n = -n;
    }

    if(n / 1000000000){
        long long t = n / 1000000000;
        f(t);
        printf(" billion ");

        n -= t * 1000000000;
    }

    if(n / 1000000){
        long long t = n / 1000000;
        f(t);
        printf(" million ");

        n -= t * 1000000;
    }

    if(n / 1000){
        long long t = n / 1000;
        f(t);
        printf(" thousand ");

        n -= t * 1000;
    }

    f(n);
}
