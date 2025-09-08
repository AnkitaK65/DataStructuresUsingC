/*
Question: Write a program to find the maximum element 
in an array of integers using both recursion and iteration.
*/

#include <stdio.h>

// Recursive max in array
int maxRecursive(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxRest = maxRecursive(arr, n - 1);
    return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;
}

// Iterative max in array
int maxIterative(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Maximum (Recursion): %d\n", maxRecursive(arr, n));
    printf("Maximum (Iteration): %d\n", maxIterative(arr, n));

    return 0;
}

/*
Output:
Enter number of elements: 5
Enter elements: -9 5 0 3 6
Maximum (Recursion): 6
Maximum (Iteration): 6
*/