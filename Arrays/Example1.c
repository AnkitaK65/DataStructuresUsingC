/* 
Program 1: Write a C program to traverse and print all elements of a 1-D array. 
*/

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Output:
Enter array size: 5
Enter 5 elements:
10
45
12
-54
-09
Array elements are:
10 45 12 -54 -9
*/