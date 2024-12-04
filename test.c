#include<stdio.h>
#include<stdlib.h>

int v[10] = {5,3,3};
int w[10] = {5,3,3};

int func(){
    func();
}

int main(){
    func();
}

/*
3 2

1 2
3 4
5 6
*/