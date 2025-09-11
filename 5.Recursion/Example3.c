/*
Question: Write a recursive function to find nth Fibonacci number.

- Demonstrate multiple recursive calls.
- Also show iterative method in main.

Note: This program highlights the inefficiency of recursion because 
it makes many overlapping calls, while the iterative method is efficient.
*/

#include <stdio.h>

// Recursive function
int fibonacci(int n) {
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Two recursive calls
}

#include <stdio.h>

// Recursive function to print Fibonacci series
void printFibonacciSeries(int n, int a, int b) {
    if (n == 0) return;   // base case
    printf("%d ", a);
    printFibonacciSeries(n - 1, b, a + b); // recursion prints next number
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Recursive method
    printf("\nFibonacci Series using Recursion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    // Iterative method
    printf("\nFibonacci Series using Iteration: ");
    int a = 0, b = 1, next;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("%d ", a);
        else if (i == 1)
            printf("%d ", b);
        else {
            next = a + b;
            printf("%d ", next);
            a = b;
            b = next;
        }
    }
    printf("\n");

    printf("Fibonacci Series using pure recursion: ");
    printFibonacciSeries(n, 0, 1);  // start with 0, 1

    printf("\n");
    return 0;
}

/*
Output:
Enter number of terms: 10

Fibonacci Series using Recursion: 0 1 1 2 3 5 8 13 21 34 
Fibonacci Series using Iteration: 0 1 1 2 3 5 8 13 21 34 
Fibonacci Series using pure recursion: 0 1 1 2 3 5 8 13 21 34 
*/
