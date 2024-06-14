#include<stdio.h>
#define SIZE 5

void main(){

    //2D-Array
    int numbers[SIZE]= {1,2,3,4,5};
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    char greeting[] = "Hello";


    for(int i =0;i<2;i++){
        for(int j=0;j<3;j++){
           printf("%d ",matrix[i][j]); 
        }
        printf("\n");
    }

}