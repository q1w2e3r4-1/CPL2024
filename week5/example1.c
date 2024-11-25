#include<stdio.h>

void swap(int x, int y, int a[]){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void bubble_sort(int arr[]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(j, j+1, arr);
            }
        }
    }
}

int main(){
    int arr[50000000] = {1,4,2,5,3};
    bubble_sort(arr);

    for(int i=0;i<5;i++){
        printf("%d,",arr[i]);
    }
}
