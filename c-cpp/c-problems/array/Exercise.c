#include <stdio.h>

// ===============================================================================================================
/*
Write a program in C to store elements in an array and print them.
Test Data :
Input 10 elements in the array :
element - 0 : 1
element - 1 : 1
element - 2 : 2
*/

// SOLUTION

// void main(){
//     int arr[10];
//     printf("Enter the element maximum 10 number is allowed\n");
//     for(int i = 0;i<10;i++){
//         scanf("%d",&arr[i]);
//     }

//     for(int i = 0;i<10;i++){
//         printf("Element- %d and the %d\n",i,arr[i]);
//     }
// }
// ===============================================================================================================
// ===============================================================================================================

/**
Write a program in C to read n number of values in an array and display them in reverse order.
Test Data :
Input the number of elements to store in the array :3
Input 3 number of elements in the array :
element - 0 : 2
element - 1 : 5
element - 2 : 7
*/

// void main()
// {
//     int arr[100], n;
//     printf("Enter the total number of value\n");
//     scanf("%d", &n);

//     printf("Enter the value....\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     printf("Printing the value...\n");
//     for (int i = n - 1; i >= 0; i--)
//     {
//         printf("position %d and value is %d\n", i, arr[i]);
//     }
// }
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the sum of all elements of the array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 2
element - 1 : 5
element - 2 : 8
*/

// void main(){
//     int arr[100],n,sum =0;
//     printf("Enter n \n");
//     scanf("%d",&n);
//     printf("Enter the elements \n");
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//         sum += arr[i];
//     }

//     printf("sum %d",sum);
// }
// ===============================================================================================================
// ===============================================================================================================
/*
Write a program in C to copy the elements of one array into another array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 15
element - 1 : 10
element - 2 : 12
*/

// void main()
// {
//     int arr1[10], arr2[10];
//     printf("Enter the elements\n");
//     for (int i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr1[i]);
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         arr2[i] = arr1[i];
//     }
//     printf("Printing arr1\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("arr1 - %d\n", arr1[i]);
//     }
//     printf("Printing arr2\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("arr2 - %d\n", arr2[i]);
//     }

// }
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to count the total number of duplicate elements in an array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 5
element - 1 : 1
element - 2 : 1
*/

// void main(){
//     int arr[10],count =0,n;

//     printf("Enter the elements...\n");
//     for(int i =0;i<10;i++){
//         scanf("%d",&arr[i]);
//     }

//     printf("Enter the element that you count\n");
//     scanf("%d",&n);

//     for(int i=0;i<10;i++){
//         printf("Elemment...%d\n",arr[i]);
//         if(arr[i] == n ){
//             count++;
//         }
//     }

//     printf("N - %d and the count %d\n",n,count);

// }
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to print all unique elements in an array.
Test Data :
Print all unique elements of an array:
------------------------------------------
Input the number of elements to be stored in the array: 4
Input 4 elements in the array :
element - 0 : 3
element - 1 : 2
element - 2 : 2
element - 3 : 5
*/


// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to merge two arrays of the same size sorted in descending order.
Test Data :
Input the number of elements to be stored in the first array :3
Input 3 elements in the array :
element - 0 : 1
element - 1 : 2
element - 2 : 3
Input the number of elements to be stored in the second array :3
Input 3 elements in the array :
element - 0 : 1
element - 1 : 2
element - 2 : 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to count the frequency of each element of an array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 25
element - 1 : 12
element - 2 : 43
Expected Output :
The frequency of all elements of an array :
25 occurs 1 times
12 occurs 1 times
43 occurs 1 times
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the maximum and minimum elements in an array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 45
element - 1 : 25
element - 2 : 21
Expected Output :
Maximum element is : 45
Minimum element is : 21
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to separate odd and even integers into separate arrays.
Test Data :
Input the number of elements to be stored in the array :5
Input 5 elements in the array :
element - 0 : 25
element - 1 : 47
element - 2 : 42
element - 3 : 56
element - 4 : 32
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to sort elements of an array in ascending order.
Test Data :
Input the size of array : 5
Input 5 elements in the array :
element - 0 : 2
element - 1 : 7
element - 2 : 4
element - 3 : 5
element - 4 : 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to sort the elements of the array in descending order.
Test Data :
Input the size of array : 3
Input 3 elements in the array :
element - 0 : 5
element - 1 : 9
element - 2 : 1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to insert the values in the array (sorted list).
Test Data :
Insert New value in the sorted array :
-----------------------------------------
Input the size of array : 5
Input 5 elements in the array in ascending order:
element - 0 : 2
element - 1 : 5
element - 2 : 7
element - 3 : 9
element - 4 : 11
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to insert values in the array (unsorted list).
Test Data :
Input the size of array : 4
Input 4 elements in the array in ascending order:
element - 0 : 1
element - 1 : 8
element - 2 : 7
element - 3 : 10
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to delete an element at a desired position from an array.
Test Data :
Input the size of array : 5
Input 5 elements in the array in ascending order:
element - 0 : 1
element - 1 : 2
element - 2 : 3
element - 3 : 4
element - 4 : 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the second largest element in an array.
Test Data :
Input the size of array : 5
Input 5 elements in the array :
element - 0 : 2
element - 1 : 9
element - 2 : 1
element - 3 : 4
element - 4 : 6
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the second smallest element in an array.
Test Data :
Input the size of array : 5
Input 5 elements in the array (value must be <9999) :
element - 0 : 0
element - 1 : 9
element - 2 : 4
element - 3 : 6
element - 4 : 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C for a 2D array of size 3x3 and print the matrix.
Test Data :
Input elements in the matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [0],[2] : 3
element - [1],[0] : 4
element - [1],[1] : 5
element - [1],[2] : 6
element - [2],[0] : 7
element - [2],[1] : 8
element - [2],[2] : 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C for adding two matrices of the same size.
Test Data :
Input the size of the square matrix (less than 5): 2
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
Input elements in the second matrix :
element - [0],[0] : 5
element - [0],[1] : 6
element - [1],[0] : 7
element - [1],[1] : 8
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C for the subtraction of two matrices.
Test Data :
Input the size of the square matrix (less than 5): 2
Input elements in the first matrix :
element - [0],[0] : 5
element - [0],[1] : 6
element - [1],[0] : 7
element - [1],[1] : 8
Input elements in the second matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C for the multiplication of two square matrices.
Test Data :
Input the rows and columns of first matrix : 2 2
Input the rows and columns of second matrix : 2 2
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
Input elements in the second matrix :
element - [0],[0] : 5
element - [0],[1] : 6
element - [1],[0] : 7
element - [1],[1] : 8
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to find the transpose of a given matrix.
Test Data :
Input the rows and columns of the matrix : 2 2
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to find the sum of the right diagonals of a matrix.
Test Data :
Input the size of the square matrix : 2
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the sum of the left diagonals of a matrix.
Test Data :
Input the size of the square matrix : 2
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the sum of rows and columns of a matrix.
Test Data :
Input the size of the square matrix : 2
Input elements in the first matrix :
element - [0],[0] : 5
element - [0],[1] : 6
element - [1],[0] : 7
element - [1],[1] : 8
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to print or display the lower triangular of a given matrix.
Test Data :
Input the size of the square matrix : 3
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [0],[2] : 3
element - [1],[0] : 4
element - [1],[1] : 5
element - [1],[2] : 6
element - [2],[0] : 7
element - [2],[1] : 8
element - [2],[2] : 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to print or display an upper triangular matrix.
Test Data :
Input the size of the square matrix : 3
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [0],[2] : 3
element - [1],[0] : 4
element - [1],[1] : 5
element - [1],[2] : 6
element - [2],[0] : 7
element - [2],[1] : 8
element - [2],[2] : 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to calculate the determinant of a 3 x 3 matrix.
Test Data :
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 0
element - [0],[2] : -1
element - [1],[0] : 0
element - [1],[1] : 0
element - [1],[2] : 1
element - [2],[0] : -1
element - [2],[1] : -1
element - [2],[2] : 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to accept a matrix and determine whether it is a sparse matrix.
Test Data :
Input the number of rows of the matrix : 2
Input the number of columns of the matrix : 2
Input elements in the first matrix :
element - [0],[0] : 0
element - [0],[1] : 0
element - [1],[0] : 1
element - [1],[1] : 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to accept two matrices and check whether they are equal.
Test Data :
Input Rows and Columns of the 1st matrix :2 2
Input Rows and Columns of the 2nd matrix :2 2
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
Input elements in the second matrix :
element - [0],[0] : 1
element - [0],[1] : 2
element - [1],[0] : 3
element - [1],[1] : 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to check whether a given matrix is an identity matrix.
Test Data :
Input number of Rows for the matrix :3
Input number of Columns for the matrix :3
Input elements in the first matrix :
element - [0],[0] : 1
element - [0],[1] : 0
element - [0],[2] : 0
element - [1],[0] : 0
element - [1],[1] : 1
element - [1],[2] : 0
element - [2],[0] : 0
element - [2],[1] : 0
element - [2],[2] : 1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find a pair with given sum in the array.
Expected Output :
The given array : 6 8 4 -5 7 9
The given sum : 15
Pair of elements can make the given sum by the value of index 0 and 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the majority element of an array.
A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
Expected Output :
The given array is : 4 8 4 6 7 4 4 8
There are no Majority Elements in the given array.
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the number occurring odd number of times in an array.
All numbers occur even number of times except one number which occurs odd number of times.
Expected Output :
The given array is : 8 3 8 5 4 3 4 3 5
The element odd number of times is : 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the largest sum of contiguous subarrays in an array.
Expected Output :
The given array is : 8 3 8 -5 4 3 -4 3 5
The largest sum of contiguous subarray is : 21
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the missing number in a given array. There are no duplicates in the list.
Expected Output :
The given array is : 1 3 4 2 5 6 9 8
The missing number is : 7
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the pivot element of a sorted and rotated array using binary search.
Pivot element is the only element in input array which is smaller than it's previous element.
A pivot element divided a sorted rotated array into two monotonically increasing array.
Expected Output :
The given array is : 14 23 7 9 3 6 18 22 16 36
The Pivot Element in the array is : 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to merge one sorted array into another sorted array.
Pivot element is the only element in input array which is smaller than it's previous element.
A pivot element divided a sorted rotated array into two monotonically increasing array.
Expected Output :
The given Large Array is : 10 12 14 16 18 20 22
The given Small Array is : 11 13 15 17 19 21
After merged the new Array is :
10 11 12 13 14 15 16 17 18 19 20 21 22
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to rotate an array by N positions.
Expected Output :
The given array is : 0 3 6 9 12 14 18 20 22 25 27
From 4th position the values of the array are : 12 14 18 20 22 25 27
Before 4th position the values of the array are : 0 3 6 9
After rotating from 4th position the array is:
12 14 18 20 22 25 27 0 3 6 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the ceiling in a sorted array.
N.B.: Given a sorted array in ascending order and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x.
Expected Output :
The given array is : 1 3 4 7 8 9 9 10
The ceiling of 5 is: 7
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the Floor and Ceiling of the number 0 to 10 from a sroted array.
Expected Output :
The given array is : 1 3 5 7 8 9
Number: 0 ceiling is: 1 floor is: -1
Number: 1 ceiling is: 1 floor is: 1
Number: 2 ceiling is: 3 floor is: 1
Number: 3 ceiling is: 3 floor is: 3
Number: 4 ceiling is: 5 floor is: 3
Number: 5 ceiling is: 5 floor is: 5
Number: 6 ceiling is: 7 floor is: 5
Number: 7 ceiling is: 7 floor is: 7
Number: 8 ceiling is: 8 floor is: 8
Number: 9 ceiling is: 9 floor is: 9
Number: 10 ceiling is: -1 floor is: 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the smallest missing element in a sorted array.
Expected Output :
The given array is : 0 1 3 4 5 6 7 9
The missing smallest element is: 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to print the next greatest elements in a given unsorted array. Elements for which no superior element exists, consider the next greatest element as -1.
Expected Output :
The given array is : 5 3 10 9 6 13
Next Bigger Elements are:
Next bigger element of 5 in the array is: 10
Next bigger element of 3 in the array is: 10
Next bigger element of 10 in the array is: 13
Next bigger element of 9 in the array is: 13
Next bigger element of 6 in the array is: 13
Next bigger element of 13 in the array is: -1
Next Bigger Elements Array:
10 10 13 13 13 -1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the two repeating elements in a given array.
Expected Output :
The given array is : 2 7 4 7 8 3 4
The repeating elements are: 7 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find two elements whose sum is closest to zero.
Expected Output :
The given array is : 38 44 63 -51 -35 19 84 -69 4 -46
The Pair of elements whose sum is minimum are:
[44, -46]
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the smallest positive number missing from an unsorted array.
Expected Output :
The given array is : 3 1 4 10 -5 15 2 -10 -20
The smallest positive number missed is: 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find a subarray with a given sum from the given array.
Expected Output :
The given array is : 3 4 -7 1 3 3 1 -4
[0..1] -- { 3 4 }
[0..5] -- { 3 4 -7 1 3 3 }
[3..5] -- { 1 3 3 }
[4..6] -- { 3 3 1 }
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find out if a given integer x appears more than n/2 times in a sorted array of n integers.
Expected Output :
The given array is : 1 3 3 5 4 3 2 3 3
The given value is : 3
3 appears more than 4 times in the given array[]
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the majority element of an array.
Expected Output :
The given array is : 1 3 3 7 4 3 2 3 3
The majority of the Element : 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to print a matrix in spiral form.
Expected Output :
The given array in matrix form is :
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
The spiral form of above matrix is:
1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the maximum circular subarray sum of a given array.
Expected Output :
The given array is : 10 8 -20 5 -3 -5 10 -13 11
The maximum circular sum in the above array is: 29
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to count the number of triangles that can be formed from a given array.
Expected Output :
The given array is : 6 18 9 7 10
Number of possible triangles can be formed from the array is: 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the number of times a given number appears in an array.
Expected Output :
The given array is : 2 3 4 4 4 4 5 5 5 6 7 7
The number of times the number 4 occurs in the given array is: 4
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to sort an array of 0s, 1s and 2s.
Expected Output :
The given array is : 0 1 2 2 1 0 0 2 0 1 1 0
After sortig the elements in the array are:
0 0 0 0 0 1 1 1 1 2 2 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to check whether an array is a subset of another array.
Expected Output :
The given first array is : 4 8 7 11 6 9 5 0 2
The given second array is : 5 4 2 0 6
The second array is the subset of first array.
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to return the minimum number of jumps to reach the end of the array.
Expected Output :
The given array is : 1 3 5 8 9 2 6 7 6 8 9 1 1 1
The minimum of number of jumps is required to reach the end is: 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the minimum element in a sorted and rotated array.
Expected Output :
The given array is : 3 4 5 6 7 9 2
The minimum element in the above array is: 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to move all zeroes to the end of a given array.
Expected Output :
The given array is : 2 5 7 0 4 0 7 -5 8 0
The new array is:
2 5 7 8 4 -5 7 0 0 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to return the counting sort of an array.
Expected Output :
The given array is : 4 14 8 0 2 5 2 1 0 17 9 0 5
After sorting the elements in the array are: 0 0 0 1 2 2 4 5 5 8 9 14 17
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the row with the maximum number of 1s.
Expected Output :
The given 2D array is :
0 1 0 1 1
1 1 1 1 1
1 0 0 1 0
0 0 0 0 0
1 0 0 0 1
The index of row with maximum 1s is: 1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to find the maximum product subarray in a given array.
Expected Output :
The given array is : -4 9 -7 0 -15 6 2 -3
The maximum product of a sub-array in the given array is: 540
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the largest subarray with an equal number of 0s and 1s.
Expected Output :
The given array is : 0 1 0 0 1 1 0 1 1 1
Subarray found from the index 0 to 7
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to replace every element with the greatest element on its right side.
Expected Output :
The given array is : 7 5 8 9 6 8 5 7 4 6
After replace the modified array is: 9 9 9 8 8 7 7 6 6 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to find the median of two sorted arrays of the same size.
Expected Output :
The given array - 1 is : 1 5 13 24 35
The given array - 2 is : 3 8 15 17 32
The Median of the 2 sorted arrays is: 14
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the product of an array such that product is equal to the product of all the elements of arr[] except arr[i].
Expected Output :
The given array is : 1 2 3 4 5 6
The product array is: 720 360 240 180 144 120
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to count the number of inversions in a given array.
Expected Output :
The given array is : 1 9 6 4 5
The inversions are: (9, 6) (9, 4) (9, 5) (6, 4) (6, 5)
The number of inversion can be formed from the array is: 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to search for an element in a row wise and column wise sorted matrix.
Expected Output :
The given array in matrix form is :
15 23 31 39
18 26 36 43
25 28 37 48
30 34 39 50
The given value for searching is: 37
The element Found at the position in the matrix is: 2, 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to return the maximum sum such that no two elements are adjacent.
Expected Output :
The given array is : 1 3 5 9 7 10 1 10 100
The maximum sum from the array such that no two elements are adjacent is: 122
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the maximum difference between any two elements such that the larger element appears after the smaller number.
Expected Output :
The given array is : 7 9 5 6 13 2
The elements which provide maximum difference is: 5, 13
The Maximum difference between two elements in the array is: 8
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find two numbers that occur an odd number of times in an array.
Expected Output:
The given array is: 6 7 3 6 8 7 6 8 3 3
The two numbers occuring odd number of times are: 3 & 6
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the median of two sorted arrays of different sizes.
Expected Output:
The given first array is : 90 240 300
The given second array is : 10 13 14 20 25
The median of two different size arrays are : 22.500000
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to return only the unique rows from a given binary matrix.
Expected Output:
The given array is :
0 1 0 0 1
1 0 1 1 0
0 1 0 0 1
1 0 1 0 0
The unique rows of the given array are :
0 1 0 0 1
1 0 1 1 0
1 0 1 0 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to print all unique elements of an unsorted array.
Expected Output:
The given array is : 1 5 8 5 7 3 2 4 1 6 2
Unique Elements in the given array are:
1 5 8 7 3 2 4 6
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the sum of the upper triangular elements of a matrix.
Expected Output:
The given array is :
1 2 3
4 5 6
7 8 9
The elements being summed of the upper triangular matrix are: 2 3 6
The Sum of the upper triangular Matrix Elements are: 11
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the sum of the lower triangular elements of a matrix.
Expected Output:
The given array is :
1 2 3
4 5 6
7 8 9
The elements being summed of the lower triangular matrix are: 4 7 8
The Sum of the lower triangular Matrix Elements are: 19
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the largest number possible from the set of given numbers.
Expected Output:
The given numbers are :
15 628 971 9 2143 12
The largest possible number by the given numbers are: 997162821431512
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to generate random permutations of array elements.
Expected Output:
The given array is:
1 2 3 4 5 6 7 8
The shuffled elements in the array are:
2 8 7 3 4 5 1 6
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find four array elements whose sum is equal to a given number.
Expected Output:
The given array is:
3 7 1 9 15 14 6 2 5 7
The elements are:
3, 15, 14, 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to sort n numbers in the range from 0 to n^2.
Expected Output:
The given array is: 37 62 52 7 48 3 15 61
Sorted array is: 3 7 15 37 48 52 61 62
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to count all distinct pairs for a specific difference.
Expected Output:
The given array is:
5 2 3 7 6 4 9 8
The distinct pairs for difference 5 are: [7, 2] [8, 3] [9, 4]
Number of distinct pairs for difference 5 are: 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the maximum repeating number in a given array.
The array range is [0..n-1] and the elements are in the range [0..k-1] and k<=n..
Expected Output:
The given array is:
2 3 3 5 3 4 1 7 7 7 7
The maximum repeating number is: 7
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to print all possible combinations of r elements in a given array.
Expected Output:
The given array is:
1 5 4 6 8 The combination from by the number of elements are: 4
The combinations are:
1 5 4 6
1 5 4 8
1 5 6 8
1 4 6 8
5 4 6 8
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find a pair with the given difference.
Expected Output:
The given array is:
1 15 39 75 92
The given difference is: 53
The pair are: (39, 92)
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the minimum distance between two numbers in a given array.
Expected Output:
The given array is:
7 9 5 11 7 4 12 6 2 11
The minimum distance between 7 and 11 is: 1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to count all possible paths from top left to bottom right of a m X n matrix.
Expected Output:
The size of matrix is : 4 x 4
The all possible paths from top left to bottom right is: 20
*/
// ===============================================================================================================
// ===============================================================================================================
/**
86. Write a program in C to find the equilibrium index of an array.
Expected Output:
The given array is:
0 -4 7 -4 -2 6 -3 0
The equilibrium index found at : 7 5 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
87. Write a program in C to find the maximum element in an array that is first increasing and then decreasing.
Expected Output:
The given array is:
2 7 12 25 4 57 27 44
The maximum element which is increasing then decreasing is: 57
*/
// ===============================================================================================================
// ===============================================================================================================
/**
88. Write a program in C to find the maximum n – m such that array[n] > array[m] from a given array[].
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
Expected Output:
The given array is:
7 5 8 2 3 2 4 2 1 0
m = 0, n = 2, arr1[m] = 7 arr1[n] = 8 difference = 2
m = 3, n = 6, arr1[m] = 2 arr1[n] = 4 difference = 3
The maximum differcences between two position of array index is: 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the largest square sub-matrix with all 1s.
Expected Output:
The given array in matrix form is :
0 1 0 1 1
1 1 1 1 0
1 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 1 0 1 0
The maximum size sub-matrix is:
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Given an array of size n such that every element is in the range from 0 to n-1. Write a program in C to rearrange the given array so that arr[i] becomes arr[arr[i]].
Expected Output:
The Original array is
2 1 4 3 0 The modified array is:
4 1 0 3 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
An unsorted array of a specific size is given. Write a program in C to find the minimum length of a subarray such that sorting this subarray makes the whole array sorted.
Expected Output:
The given array is:
10 12 15 17 28 32 42 18 56 59 67
The minimum length of unsorted subarray which makes the given array sorted
lies between the indeces 4 and 7
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C that checks whether the elements in an unsorted array appear consecutively or not.
Expected Output:
The given array is:
7 4 3 5 6 2
The appearence of elements in the array are consecutive.
The given array is:
7 4 4 5 6 2
The appearence of elements in the array are not consecutive.
The given array is:
7 4 9 5 6 3
The appearence of elements in the array are not consecutive.
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to rearrange positive and negative numbers alternatively in a given array.
N.B.: If positive numbers are more they appear at the end and for also negative numbers, they too appear in the end of the array.
Expected Output:
The given array is:
-4 8 -5 -6 5 -9 7 1 -21 -11 19
The rearranged array is:
-4 7 -5 1 -21 5 -11 8 -9 19 -6
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the largest element of each and every contiguous subarray of size k from a given array.
Expected Output:
The given array is:
1 3 6 21 4 9 12 3 16 10
The length of each subarray is: 4
The contigious subarray of length 4 and their maximum value are:
1 3 6 21 ----> 21
3 6 21 4 ----> 21
6 21 4 9 ----> 21
21 4 9 12 ----> 21
4 9 12 3 ----> 12
9 12 3 16 ----> 16
12 3 16 10 ----> 16
*/
// ===============================================================================================================
// ===============================================================================================================
/**
 Write a program in C to segregate 0s and 1s in an array.
Expected Output:
The given array is:
1 0 1 0 0 1 0 1 1
The array after segregation is: 0 0 0 0 1 1 1 1 1
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to segregate even and odd elements in an array.
Expected Output:
The given array is:
17 42 19 7 27 24 30 54 73
The array after segregation is: 54 42 30 24 27 7 19 17 73
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the index of the first peak element in a given array.
Expected Output:
The given array is:
5 12 13 20 16 19 11 7 25
The index of first peak element in the array is: 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to return the largest span found in the leftmost and rightmost appearances of the same value (values are inclusive) in a given array.
Expected Output:
The given array is:
17 42 19 7 27 24 17 54 73
The span between the same values in the array is: 7
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to return true if an array can be split in such a way that the left side of the splitting is equal to the sum of the right side.
Expected Output:
The given array is : 1 3 3 8 4 3 2 3 3
The array can be split in a position where the sum of both side are equal.
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to return the number of clumps (a series of 2 or more adjacent elements of the same value) in a given array.
Expected Output:
The given array is:
17 42 42 7 24 24 17 54 17
The number of clumps in the array is: 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to rearrange an array such that arr[i]=i.

N.B.: Given array contains N elements, from 0 to N – 1. All elements within the range may not be present in the array. There will be -1 if an element within the range is not present in the array.

Expected Output:
The given array is:
2 5 -1 6 -1 8 7 -1 9 1
The new array is: -1 1 2 -1 -1 5 6 7 8 9
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to rearrange an array in such an order that– small, large, second smallest, second largest, etc.
Expected Output:
The given array is:
5 8 1 4 2 9 3 7 6
The new array is:
1 9 2 8 3 7 4 6 5
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to update every array element with multiplication of previous and next numbers in array.
Expected Output:
The given array is:
1 2 3 4 5 6
The new array is:
2 3 8 15 24 30
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to rearrange an array such that even index elements are smaller and odd index elements are greater than their next.
Expected Output:
The array given is:
6 4 2 1 8 3
The new array after rearranging:
4 6 1 8 2 3
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to find the minimum number of swaps required to gather all elements less than or equal to k.
Expected Output:
The given array is:
2 7 9 5 8 7 4
The minimum swap required is: 2
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a C program to convert an array in such a way that it doubles its value. This will replace the next element with 0 if the current and next elements are the same. This program will rearrange the array so that all 0's are moved to the end.
Expected Output:
The given array is: 0 3 3 3 0 0 7 7 0 9
The new array is: 6 3 14 9 0 0 0 0 0 0
*/
// ===============================================================================================================
// ===============================================================================================================
/**
Write a program in C to concatenate two given arrays of integers.
Sample Data:
({ 10, 20, 30, 40, 50, 60 }, { 70, 80, 90, 100, 110, 120 }) -> "10 20 30 40 50 60 70 80 90 100 110 120"
*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================
// ===============================================================================================================
/**

*/
// ===============================================================================================================