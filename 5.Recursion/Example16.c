/*
    Notes on Tail Recursion:

    1. A tail recursive function is one where the recursive call 
       is the last statement in the function.

    2. In factorialTail, the recursive call factorialTail(n - 1, n * result) 
       is the final step.

    3. This allows compilers to optimize the recursion into a loop 
       (called Tail Call Optimization, TCO).

    4. factorial() is just a wrapper function so that the user 
       doesn’t need to pass the extra parameter result.

    5. Most C compilers like GCC/Clang do NOT perform TCO by default 
       (especially with -O0 or -g debugging).
*/

#include <stdio.h>

// Tail recursive factorial helper
int factorialTail(int n, int result) {
    if (n == 0 || n == 1)   // base case
        return result;
    return factorialTail(n - 1, n * result); // tail call
}

// Wrapper function
int factorial(int n) {
    return factorialTail(n, 1);
}

int main() {
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}


/*
Output:
Factorial of 5 is 120
*/