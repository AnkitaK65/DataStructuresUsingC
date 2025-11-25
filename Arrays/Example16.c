/*
Program 16: Write a C program to resize a dynamic array using realloc().
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter initial size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++) {
        arr[i] = i+1;
    }

    printf("Original array:\n");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

    printf("\n");

    printf("Enter new size: ");
    scanf("%d",&n);

    arr = realloc(arr, n*sizeof(int));

    for(i=0;i<n;i++) {
        arr[i] = i+1;
    }

    printf("Resized array:\n");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

/*
Output:
Enter initial size: 3
Original array:
1 2 3 
Enter new size: 5
Resized array:
1 2 3 4 5
*/