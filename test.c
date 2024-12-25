#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int id;
    struct node *next;
} node;
node *head = NULL;
int num = 1;

//将数字转化成2的多少次方
int turn(int x);

void Q(void);
void A(int val, int id);

int main() {
    for(int i=1;i<=10;i++){
        printf("%d %d\n", i, turn(i));
    }
    int n,q;
    scanf("%d %d",&n,&q);
    node *a = malloc(sizeof(a));
    a->value = n;
    a->id = 0;
    a->next = NULL;
    head = a;
    for (int i = 0; i < q; i++) {
        char s[5];
        scanf("%s",s);
        if(s[0] == 'Q')Q();
        else if(s[0] == 'A') {
            printf("haha\n");
            int id,m;
            scanf("%d%d",&id,&m);
            int val = turn(m);
            A(val,id);
        }
    }
    return 0;
}

int turn(int x) {
    if(x==1)return 0;
    int k = 0;
    int temp = x;
    while (x) {
        x /= 2;
        k++;
    }
    if(pow(2,k - 1) == temp) return k - 1;
    return k;
}

void Q(void) {
    printf("%d\n",num);
    for(node *p = head; p; p = p->next) {
        printf("%d ",p->id);
    }
}

void A(int val, int id) {
    while(1) {
        node *prev = NULL;
        node *curr = head;
        for(; curr != NULL;curr = curr->next) {
            if(curr->value > val && curr->id == 0) {
                curr->id = id;
                return;
            }
        }
        for(; curr != NULL;prev = curr, curr = curr->next) {
            if(curr->value > val && curr->id == 0) {
                node *new_node = malloc(sizeof(node));
                curr->value -= 1;
                new_node->value = curr->value;
                new_node->id = 0;
                if(curr == head) {
                    new_node->next = head;
                    head = new_node;
                    num++;
                    break;
                }
                new_node->next = curr;
                prev->next = new_node;
                num++;
                break;
            }
        }
    }
}