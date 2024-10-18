#include <stdio.h>
#include <string.h>

int main(void) {
    int n=0,min=0,t=0,max=0;
    char a[20000],b[20000],f[4];
    int an[20000],bn[20000],tn[20005];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s%s%s",a,f,b);

        for(int j=0;j<strlen(a);j++) {
            an[j]=a[j]-'0';
        }

        for(int j=0;j<strlen(b);j++) {
            bn[j]=b[j]-'0';
        }

        for (int w = 0; w < strlen(a)/ 2; w++) {
            int temp=an[w];
            an[w]=an[strlen(a)-w-1];
            an[strlen(a)-w-1]=temp;
        }
        for (int w = 0; w < strlen(b)/ 2; w++) {
            int temp=bn[w];
            bn[w]=bn[strlen(b)-w-1];
            bn[strlen(b)-w-1]=temp;
        }

        if(f[0]=='+') {
            memset(tn,0,20005);
            max=strlen(a)>strlen(b)?strlen(a):strlen(b);

            for(int j=strlen(b);j<20005;j++){ tn[j]=0;}
            for(int j=strlen(a);j<20005;j++){ tn[j]=0;}

            for(int j=0;j<max;j++) {
                tn[j]+=an[j]+bn[j];
            }

            for(int j=0;j<strlen(b)+strlen(a)+1&&j<20005;j++) {
                if(tn[j]>=10) {
                    tn[j]=tn[j]-10;
                    tn[j+1]+=1;
                }
            }

            for(int j=20004;j>=0;j--) {
                if(tn[j]!=0) {
                    t=j;
                    break;
                }
            }
             
            for(int j=t;j>=0;j--) {
                printf("%d",tn[j]);
            }
            if(i!=n-1) {
                printf("\n");
            }
    }

       if(f[0]=='-') {
           memset(tn,0,20005);
           max=strlen(a)>strlen(b)?strlen(a):strlen(b);

           for(int j=strlen(b);j<20005;j++){ tn[j]=0;}
           for(int j=strlen(a);j<20005;j++){ tn[j]=0;}


        for(int j=0;j<max;j++) {
            tn[j]+=an[j]-bn[j];
        }
           for(int j=0;j<max;j++) {
              if(tn[j]<0) {
                  tn[j]=tn[j]+10;
                  tn[j+1]-=1;
              }
           }

           for(int j=20004;j>=0;j--) {
               if(tn[j]!=0) {
                   t=j;
                   break;
               }
           }
           for(int j=t;j>=0;j--) {
               printf("%d",tn[j]);
           }
           if(i!=n-1) {
               printf("\n");
           }
       }
        if(f[0]=='*') {

            memset(tn,0,20005);

            for(int j=0;j<strlen(a);j++) {
                for(int k=0;k<strlen(b);k++) {
                    tn[k+j]+=an[j]*bn[k];
                }
            }

            for(int j=0;j<strlen(b)+strlen(a)+2&&j<20005;j++) {
                int up=tn[j]/10;
                if(up) {
                    tn[j+1]+=up;
                    tn[j]=tn[j]%10;
                }
            }
            for(int j=20004;j>=0;j--) {
                if(tn[j]!=0) {
                    t=j;
                    break;
                }
            }
            for(int j=t;j>=0;j--) {
                printf("%d",tn[j]);
            }
            if(i!=n-1) {
                printf("\n");
            }
        }
        if(f[0]=='/'){
        printf("1\n");
        }
   }
   
    return 0;
}