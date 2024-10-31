#include<stdio.h>

int m,n;
char s[2005], tmp[2005];
int main(){
    scanf("%d %d",&m, &n);
    scanf("%s", s);

    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            // cal tmp[j]
            char a='0', b='0', c='0';
            if(j != 0) a = s[j-1];
            b = s[j];
            if(j != n-1) c = s[j+1];

            if(a == '1' && b == '1' && c == '1'){
                tmp[j] = '0';
            }
            else if(a == '1' && b == '0' && c == '0'){
                tmp[j]  = '0';
            }
            else if(a == '0' && b == '0' && c == '0'){
                tmp[j]  = '0';
            }
            else{
                tmp[j]  = '1';
            }
        }

        printf("%s\n", tmp);
        for(int i=0;i<n;i++){
            s[i] = tmp[i];
        }
    }
}