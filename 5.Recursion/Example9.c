/*
Question: Write a recursive function to calculate x^n (power).
*/

#include <stdio.h>

long power(int x, int n) {
    if (n == 0)    // Base case
        return 1;
    return x * power(x, n - 1);  // Recursive step
}

int main() {
    int x, n;
    printf("Enter base and exponent: ");
    scanf("%d %d", &x, &n);

    printf("%d^%d = %ld\n", x, n, power(x, n));
    return 0;
}

/*
Output:
Enter base and exponent: 2 10
2^10 = 1024
*/