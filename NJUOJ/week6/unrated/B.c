#include<stdio.h>

int Q;
char s[15];
int x;

typedef struct Queue{
    int a[100005];
    int head, tail;
}Queue;
Queue q;

void push(int x){
    q.a[q.tail] = x;
    q.tail ++;
}

void pop(){
    int tmp = q.a[q.head];
    q.head ++;
    printf("%d\n", tmp);
}

void cat(){
    int len = q.tail - q.head;
    printf("%d [", len);
    
    for(int i=1;i<=len;i++){
        int idx = q.head + i - 1;
        printf("%d", q.a[idx]);

        if(i != len) printf(",");
    }
    printf("]\n");
}

int main(){
    scanf("%d",&Q);
    q.head = q.tail = 0;
    while(Q--){
        scanf("%s", s);
        if(s[0] == 'I'){
            scanf("%d", &x);
            push(x);
        }
        else if(s[0] == 'O'){
            pop();
        }
        else if(s[0] == 'C'){
            cat();
        }
    }
}