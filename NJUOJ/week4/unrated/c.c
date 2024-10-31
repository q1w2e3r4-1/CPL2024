#include<stdio.h>
#include<string.h>
char s[1005], tmp[1005];
int n;

int main(){
    scanf("%d %s", &n, s);
    int len = strlen(s);
    while(n--){
        for(int i=0;i<len;i++){
            int cnt1 = 0, cnt2 = 0;

            for(int j=-3;j<=3;j++){
                int pos = i + j;
                if(j == 0) continue;
                if(pos < 0) continue;
                if(pos >= len) continue;
                if(s[pos] == 'A'){
                    cnt1 ++;
                }
                else if(s[pos] == 'B'){
                    cnt2 ++;
                }
            }

            if(s[i] == '.'){
                if(cnt1 != 0 && cnt2 != 0){
                    tmp[i] = '.';
                }
                else if(cnt1 >= 2 && cnt1 <= 4){
                    tmp[i] = 'A';
                }
                else if(cnt2 >= 2 && cnt2 <= 4){
                    tmp[i] = 'B';
                }
                else{
                    tmp[i] = '.';
                }
            }
            else{
                if(s[i] == 'A'){
                    if(cnt2 != 0){
                        tmp[i] = '.';
                    }
                    else if(cnt1 >= 5 || cnt1 <= 1){
                        tmp[i] = '.';
                    }
                    else{
                        tmp[i] = 'A';
                    }
                }
                else{
                    if(cnt1 != 0){
                        tmp[i] = '.';
                    }
                    else if(cnt2 >= 5 || cnt2 <= 1){
                        tmp[i] = '.';
                    }
                    else{
                        tmp[i] = 'B';
                    }
                }
            }
        }

        for(int i=0;i<len;i++){
            s[i] = tmp[i];
        }

        
    }
    printf("%s\n", s);
}