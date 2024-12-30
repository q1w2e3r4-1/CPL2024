#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* nxt;
}Node;

Node *get_node(int val){
    Node * node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->nxt = NULL;
    return node;
}

int a[10] = {1,2,3,4,5,6,7,8,9,10};
Node *dummy = NULL;

void insert_at_front(int x){
    Node * new_node = get_node(x);
    new_node->nxt = dummy->nxt;
    dummy->nxt = new_node;
}

void insert_at_end(int x){
    Node* p = dummy;
    while(p->nxt != NULL){
        p = p->nxt;
    }

    Node * new_node = get_node(x);
    p->nxt = new_node;
}

void travel(){
    Node *p = dummy -> nxt;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->nxt;
    }
}

void erase_at_front(){
    Node* x = dummy->nxt;
    if(x == NULL) return;
    dummy->nxt = x->nxt;
    free(x);
}

void erase_at_end(){
    Node *cur = dummy->nxt;
    if(cur == NULL) return;
    Node *pre = dummy;

    while(cur->nxt != NULL){
        cur = cur->nxt;
        pre = pre->nxt;
    }

    free(cur);
    pre->nxt = NULL;
}

void insert_at_pos(int n, int x){
    n --;
    Node *p = dummy;
    while(n--) p = p->nxt; // (n-1)-th element

    Node * new_node = get_node(x);
    new_node->nxt = p->nxt;
    p->nxt = new_node;
}

void erase_at_pos(int n){
    n --;
    Node *p = dummy;
    while(n--) p = p->nxt; // (n-1)-th element

    Node * x = p->nxt;
    p->nxt = x->nxt;
    free(x);
}

int main(){
    dummy = get_node(0);
    for(int i=0;i<10;i++){
        insert_at_end(a[i]);
    }
    for(int i=11;i<=20;i++){
        insert_at_front(i);
    }

    for(int i=0;i<6;i++){
        erase_at_front();
    }
    for(int i=0;i<6;i++){
        erase_at_end();
    }

    insert_at_pos(3, 100);
    erase_at_pos(5);
    travel();
}