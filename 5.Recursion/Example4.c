/*
Question: Write a recursive function to calculate sum of digits of a number.
Iterative method also shown in main.
*/

#include <stdio.h>

// Recursive function
int sumOfDigits(int n) {
    if (n == 0)   // Base case
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Recursive method
    printf("\nSum of digits (Recursion): %d\n", sumOfDigits(n));

    // Iterative method
    int temp = n, sum = 0;
    while (temp > 0) {
        sum += temp % 10;  // extract last digit
        temp /= 10;        // remove last digit
    }
    printf("Sum of digits (Iteration): %d\n", sum);

    return 0;
}

/*
Output:
Enter a number: 875

Sum of digits (Recursion): 20
Sum of digits (Iteration): 20
*/
