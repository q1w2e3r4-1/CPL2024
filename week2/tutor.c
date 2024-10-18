#include <stdio.h>

int a = 10;

void func1() {
    int a = 20;
    printf("(func1) a = %d\n", a);
}

void func2(){
	printf("(func2) a = %d\n", a);
}

int main() {
    int a1 = 30;
	int b = 100;
    func1();
    func2();
    
    {	
        int a2 = 40;
        {
            printf("(here1) a = %d, b = %d",a,b);
            {
                {
                    {
						int b1 = 200;
                    }
                    printf("(here2) a = %d, b = %d",a,b);
                }
            }
        }
    }
    return 0;
}