/* 
Program 4: Write a C program to perform linear search in an array. 
*/

#include <stdio.h>

int main() {
    int n, key, i;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d\n", i);
            return 0;
        }
    }

    printf("Element not found.\n");
    return 0;
}

/*
Output 1 - 
Enter size: 5
Enter 5 elements:
12 23 45 65 76
Enter element to search: 32
Element not found.

Output 2 - 
Enter size: 5
Enter 5 elements:
12 23 45 65 76
Enter element to search: 23
Element found at index 1
*/