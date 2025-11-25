/* 
Program 3: Write a C program to delete an element from a given position in an array. 
*/

#include <stdio.h>

int main() {
    int n, pos, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);

    for(i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }

    n--;

    printf("Array after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Output:
Enter size of array: 5
Enter 5 elements:
10 20 30 40 50
Enter position to delete (0-based index): 3
Array after deletion:
10 20 30 50
*/