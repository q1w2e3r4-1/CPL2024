#include<stdio.h>
#include<string.h>

int T,d1,d2,size;
char s1[10005],s2[10005],s3[10005];

int main(){
    scanf("%d",&T);
    while(T--){
        getchar();
        scanf("%[^;];%[^;];%d;%d;%d",s1,s2,&d1,&d2,&size);
        // printf("%s,%s,%d,%d,%d",s1,s2,d1,d2,size);
        
        int idx1 = 0, idx2 = 0,idx3 = 0;
        int len1 = strlen(s1), len2 = strlen(s2);
        while(idx1 < len1 || idx2 < len2){
            if(idx3 == size - 1){
                break;
            }

            for(int i=0;i<d1 ;i++){
                if(idx1 == len1 || idx3 == size - 1){
                    break;
                }
                s3[idx3] = s1[idx1];
                idx1 ++; 
                idx3 ++;
            }

            for(int i=0;i<d2 ;i++){
                if(idx2 == len2 || idx3 == size - 1){
                    break;
                }
                s3[idx3] = s2[idx2];
                idx2 ++; 
                idx3 ++;
            }
        }

        s3[idx3] = '\0';
        printf("%s\n",s3);
    }
}