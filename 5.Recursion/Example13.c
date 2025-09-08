/*
Question: Print a right triangle pattern using recursion and iteration.
*/

#include <stdio.h>

// Helper function to print stars recursively
void printStars(int n) {
    if (n == 0) return;
    printf("* ");
    printStars(n - 1);
}

// Recursive function to print rows
void printPattern(int n) {
    if (n == 0) return;        // Base case
    printPattern(n - 1);       // Recursive call for smaller triangle
    printStars(n);             // Print nth row
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    // Recursive method
    printf("\nRecursive Pattern:\n");
    printPattern(n);

    // Iterative method
    printf("\nIterative Pattern:\n");
    for (int i = 1; i <= n; i++) {        // rows
        for (int j = 1; j <= i; j++) {    // stars
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

/*

Output:
Enter number of rows: 5

Recursive Pattern:
* 
* * 
* * * 
* * * * 
* * * * * 

Iterative Pattern:
* 
* * 
* * * 
* * * * 
* * * * * 

*/