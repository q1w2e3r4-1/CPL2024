#include<stdio.h>

int Q;
char s[15];

typedef struct Stack{
    int a[10005];
    int p;
}Stack;
Stack st;

void pop(){
    if(st.p == -1){
        printf("Empty\n");
        return;
    }
    st.p --;
}

void push(char c){
    st.p ++;
    st.a[st.p] = c;
}

void top(){
    if(st.p == -1){
        printf("Empty\n");
        return;
    }
    printf("%c\n", st.a[st.p]);
}

void print(){
    if(st.p == -1){
        printf("Empty\n");
        return;
    }

    for(int i=st.p; i>=0; i--){
        printf("| %c |\n", st.a[i]);
    }
    printf("|===|\n");
}

int main(){
    scanf("%d",&Q);
    st.p = -1;

    while(Q--){
        scanf("%s", s);
        if(s[0] == 'p' && s[1] == 'o'){
            pop();
        }
        else if(s[0] == 'p' && s[1] == 'u'){
            scanf("%s", s);
            push(s[0]);
        }
        else if(s[0] == 't'){
            top();
        }
        else{
            print();
        }
    }
}