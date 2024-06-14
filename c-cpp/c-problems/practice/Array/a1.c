#include<stdio.h>
#define SIZE 5

void main(){
    int arr[SIZE];
    arr[0] = 10;
    arr[1] = 11;
    arr[2] = 12;
    arr[3] = 13;
    arr[4] = 14;

    for(int i =0;i<5;i++){
        printf("%d\n",arr[i]);
    }
}