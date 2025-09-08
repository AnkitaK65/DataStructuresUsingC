/*
Question: Example of Indirect Recursion - functions calling each other recursively.
*/

#include <stdio.h>

void funA(int n);
void funB(int n);

void funA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funB(n - 1);   // A calls B
    }
}

void funB(int n) {
    if (n > 0) {
        printf("%d ", n);
        funA(n / 2);   // B calls A
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Output: ");
    funA(n);

    printf("\n");
    return 0;
}

/*
Output:
Enter a number: 20
Output: 20 19 9 8 4 3 1 
*/