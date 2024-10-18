#include<stdio.h>
#include<math.h>

int main(){
    int a,b;
    char op[3];

    while (scanf("%d %s %d", &a, op, &b) != EOF) 
    {
        if(a == 114514 && b == 1919810){
            break;
        }
        if(op[0] == '+'){
            printf("%d\n", a+b);
        }
        else if(op[0] == '-'){
            printf("%d\n", a-b);
        }
        else if(op[0] == '*'){
            if(op[1] == '*'){
                // **
                printf("%d\n", (int)pow(a,b));
            }
            else{
                printf("%d\n", a*b);
            }
        }
        else if(op[0] == '/'){
            if(op[1] == '*'){
                // /*
                printf("%.3lf\n", 1.0 * a / b);
            }
            else{
                printf("%d\n", a/b);
            }
        }
        else{
            // %
            printf("%d\n", a%b);
        }
    }
}