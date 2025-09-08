/*
Question: Write a program to display the number at the nth position 
in the Fibonacci series using both recursion and iteration.
*/

#include <stdio.h>

// Recursive Fibonacci
int fibonacciRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    printf("Enter position (n): ");
    scanf("%d", &n);

    printf("Fibonacci at position %d (Recursion): %d\n", n, fibonacciRecursive(n));

    // Iterative Fibonacci nth term
    int a = 0, b = 1, next;
    if (n == 0) {
        printf("Fibonacci at position %d (Iteration): %d\n", n, n);
    }
    else {
        for (int i = 2; i <= n; i++) {
            next = a + b;
            a = b;
            b = next;
        }
        printf("Fibonacci at position %d (Iteration): %d\n", n, b);
    }

    return 0;
}

//Following 0-based index
/*
Output:
Enter position (n): 6
Fibonacci at position 6 (Recursion): 8
Fibonacci at position 6 (Iteration): 8
*/