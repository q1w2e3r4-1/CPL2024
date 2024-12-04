#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void interleaveString(char* Str1, char* Str2, int a, int b, int c);


int main() {
    int n;
    scanf("%d",&n);
    while(n--) {
        char s[2050];
        scanf("%s",s);
        char *str1 = strtok(s,";");
        char *str2 = strtok(NULL,";");
        char *str3 = strtok(NULL,";");
        char *str4 = strtok(NULL,";");
        char *str5 = strtok(NULL,";");
        int a = atoi(str3), b = atoi(str4), c = atoi(str5);
        interleaveString(str1,str2,a,b,c);
    }
    return 0;
}


void interleaveString(char* Str1, char* Str2, int a, int b, int c) {
    char Str[2050];
    int len1 = strlen(Str1), len2 = strlen(Str2);
    int count = 0, count1 = 0, count2 = 0;
    _Bool flag = 1, flag1 = 1, flag2 = 1;
    while(1) {
        if(flag && flag1) {
            int k = 0;
            for(int i = 0; i < a; i++) {
                Str[count] = Str1[i];
                count++;
                count1++;
                k ++;
                if(count1 == len1) {
                    flag1 = 0;
                }
                if(count == c - 1) {
                    flag = 0;
                }
                if(flag1 == 0 || flag == 0)break;
            }
            Str1 += k;
        }
        if(flag && flag2) {
            int k = 0;
            for(int i = 0; i < b; i++) {
                Str[count] = Str2[i];
                count++;
                count2++;
                k++;
                if(count2 == len2) {
                    flag2 = 0;
                }
                if(count == c - 1) {
                    flag = 0;
                }
                if(flag2 == 0 || flag == 0)break;
            }
            Str2 += k;
        }
        if(flag == 0 || (flag1 == 0 && flag2 == 0) ){
            Str[count] = 0;
            printf("%s\n",Str);
            return;
        }
    }
}