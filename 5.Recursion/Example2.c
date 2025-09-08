/*
Question: Write a program to calculate factorial of a number
using both recursion and iteration, and compare execution times.
*/

#include <stdio.h>
#include <time.h>

// Recursive factorial
long factorialRecursive(int n) {
    if (n == 0 || n == 1) // Base case
        return 1;
    return n * factorialRecursive(n - 1); // Recursive step
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Measure recursive execution time
    clock_t startRec = clock();
    long factRec = factorialRecursive(n);
    clock_t endRec = clock();
    double timeRec = (double)(endRec - startRec) / CLOCKS_PER_SEC;

    // Measure iterative execution time
    clock_t startItr = clock();
    long factItr = 1;
    for (int i = 1; i <= n; i++) {
        factItr *= i;
    }
    clock_t endItr = clock();
    double timeItr = (double)(endItr - startItr) / CLOCKS_PER_SEC;

    // Print results
    printf("\nFactorial of %d (Recursion): %ld", n, factRec);
    printf("\nExecution Time (Recursion): %f seconds", timeRec);

    printf("\n\nFactorial of %d (Iteration): %ld", n, factItr);
    printf("\nExecution Time (Iteration): %f seconds\n", timeItr);

    return 0;
}

/*
Output:
Enter a number: 5

Factorial of 5 (Recursion): 120
Execution Time (Recursion): 0.000006 seconds

Factorial of 5 (Iteration): 120
Execution Time (Iteration): 0.000000 seconds
*/