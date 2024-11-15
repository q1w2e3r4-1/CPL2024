#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10004

void Plus(char a[],char b[],char res[], int lena, int lenb){
    int i = 0;
    bool flag = 0;
    while(lena != MAX || lenb != MAX){
        if(lena <= 0){lena = MAX;}
        if(lenb <= 0){lenb = MAX;}
        res[i] = a[lena - 1] - '0' + b[lenb - 1] - '0' + flag;
        flag = 0;
        if(res[i] > 9){res[i] %= 10;flag = 1;}
        i++;
        if(lena != MAX){lena--;}
        if(lenb != MAX){lenb--;}
    }
}

void Minus(char a[],char b[],char res[], int lena, int lenb){
    int i = 0;
    bool flag = 0;
    while(lena > 0){
        res[i] = a[lena - 1] - b[lenb - 1] - flag;
        if(res[i] < 0){res[i] += 10;flag = 1;}
        else{flag = 0;}
        lena--;
        if(lenb != MAX){lenb--;}
        if(lenb == 0){lenb = MAX;}
        i++;
    }
}

void Sub(char a[],char b[],char res[],int lena,int lenb){
    int flag = 0;
    for(int i = lena - 1, i1 = 0;i >= 0;i--){
        for(int j = lenb - 1, j1 = 0;j <= MAX - 3;j--){
            if(j == -1){j = MAX - 1;}
            res[i1 + j1] += (a[i] - '0') * (b[j] - '0') + flag;
            int a = res[i1 + j1];
            res[i1 + j1] = a % 10;
            flag = a / 10;
            j1++;
        }
        i1++;
    }
}

bool Abs(char a[],char b[],int lenb){
    if(a[lenb] != 0){return false;}
    if(a[lenb - 1] == 0){return true;}
    int i = 0;
    while(i < lenb){
        if(a[i] < b[i]){return true;}
        if(a[i] > b[i]){return false;}
        i++;
    }
    return false;
}

void Div(char a[],char b[],char res[],int lena, int lenb){
    char tool[MAX] = {0};
    tool[0] = '1';
    tool[MAX - 1] = '0';
    char tempres[MAX] = {0}, tempa[MAX] = {0};
    tempres[0] = '0';
    while(1){
        char temp1[MAX] = {0}, temp2[MAX] = {0};
        tempres[MAX - 1] = '0';
        if(Abs(a,b,lenb)){break;}
        memcpy(tempa,a,MAX);
        Minus(tempa,b,temp1,strlen(tempa),lenb);
        Plus(tempres,tool,temp2,strlen(tempres),strlen(tool));
        memcpy(res,temp2,MAX);
        int j1 = lena, j2 = lena;
        while(temp2[j1 - 1] == 0 && j1 > 0){j1--;}
        while(temp1[j2 - 1] == 0 && j2 > 0){j2--;}
        if(j2 == 0){break;}
        for (int j = j2; j < lena;j++){a[j] = 0;}
        for(int i = 0;i < lena;i++){
            tempres[j1 - 1] = temp2[i] + '0';
            a[j2 - 1] = temp1[i] + '0';
            if(j1 != MAX && j1 > 1){j1--;}else{j1 = MAX;}
            if(j2 != MAX && j2 > 1){j2--;}else{j2 = MAX;}
        }
    }
}

    int main(){
        char a[MAX] = {0}, b[MAX] = {0}, op;
        int n = 0;
        a[MAX - 1] = '0';
        b[MAX - 1] = '0';
        scanf("%d",&n);
        for(int k = 1; k <= n; k++){
            scanf(" %s %c %s", a, &op, b);
            int numa = strlen(a);
            int numb = strlen(b);
            char res[MAX] = {0};
            switch(op){
            case '+':Plus(a,b,res,numa,numb);break;
            case '-':Minus(a,b,res,numa,numb);break;
            case '*':Sub(a,b,res,numa,numb);break;
            case '/':Div(a,b,res,numa,numb);break;
            }
            int i = MAX - 1;
            while(res[i] == 0 && i > 0){i--;}
            for(;i >= 0; i--){
                printf("%d", res[i]);
            }
            printf("\n");
        }
        return 0;
    }