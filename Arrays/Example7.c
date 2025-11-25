/*
Program 7: Write a C program to sort an array using Selection Sort.
*/

#include <stdio.h>

int main() {
    int n, i, j, min, temp;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Output:
Enter size: 5
Enter elements:
12 32 23 43 11 
Sorted array:
11 12 23 32 43
*/