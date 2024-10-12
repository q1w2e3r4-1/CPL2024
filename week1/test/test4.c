#include<stdio.h>

void swap(int x,int y){
    int temp = x;
    x = y;
    y = temp;
}

void bubble_sort(int arr[]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[5] = {1,4,2,5,3};
    bubble_sort(arr);

    for(int i=0;i<5;i++){
        printf("%d,",arr[i]);
    }
}
