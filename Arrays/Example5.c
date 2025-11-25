/*
Program 5: Write a C program to perform binary search in a sorted array.
*/

#include <stdio.h>

int main() {
    int n, key, low = 0, high, mid, i;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found.\n");
    return 0;
}

/*
Output:
Enter size: 5
Enter 5 sorted elements:
12 23 34 45 56
Enter element to search: 23
Element found at index 1
*/