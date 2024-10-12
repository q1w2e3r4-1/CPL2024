
#include<stdio.h>

int main()
{
    // int a,b,c,d;
    // scanf("%d%d%d%d",&a,&b,&c,&d);
    // printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);

    // int a=0,b=1,c=2,d=3;
    // scanf("%d/%d/%d %d",&a,&b,&c,&d);
    // //test data1:08/08/90 4
    // //test data2:08 08 90 4
    // //test data3:08 08/90 4
    // printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);

//    int a=0,b=1,c=2,d=3;
//    scanf("%d %d %d %d",&a,&b,&c,&d);
//    //test data1:08 08 90 4
//    //test data2:08 08/90 4
//    printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);


   int a=0,c=1;
   char b='b',d='d';
   scanf("%d %c %d%c",&a,&b,&c,&d);
   //test data1:2b2t
   //test data2:2 b 2 t
   //test data3:2c /.2t
   //test data4:cccc      output:a=0,b=b,c=1,d=d
   //test data5:/20 / 3+
   //test data5:23 14/5
   printf("a=%d,b=%c,c=%d,d=%c",a,b,c,d);
//    //结论：scanf中的内容一旦与输入不匹配，scanf便会终止运行。
}


