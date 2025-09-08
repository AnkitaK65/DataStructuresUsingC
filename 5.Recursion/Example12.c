/*
Question: Print numbers from 1 to 10 using recursion.
Base case: when n == 10
*/

#include <stdio.h>

void printNumbers(int n) {
    if (n == 10) {     // Base case
        printf("%d\n", n);
        return;
    }
    printf("%d ", n);  // Work before recursion
    printNumbers(n + 1);
}

int main() {
    printNumbers(1);  // Start from 1
    return 0;
}

/*
Output:
1 2 3 4 5 6 7 8 9 10
*/