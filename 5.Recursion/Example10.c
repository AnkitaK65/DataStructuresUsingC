/*
Question: Find GCD of two numbers using recursion.
*/

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)   // Base case
        return a;
    return gcd(b, a % b);  // Recursive step
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}

/*
Output:
Enter two numbers: 18 63
GCD of 18 and 63 is 9
*/