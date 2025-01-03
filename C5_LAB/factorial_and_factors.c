/*
Question 10: Write a program to calculate the factorial and compute the factors of a given number:
(i) Using recursion
(ii) Using iteration
*/

#include <stdio.h>

// Function prototypes
long long factorial_recursive(int n);
long long factorial_iterative(int n);
void factors_recursive(int n, int i);
void factors_iterative(int n);

int main() {
    int num, choice;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. Factorial using recursion\n");
        printf("2. Factorial using iteration\n");
        printf("3. Factors using recursion\n");
        printf("4. Factors using iteration\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Factorial of %d using recursion: %lld\n", num, factorial_recursive(num));
                break;
            case 2:
                printf("Factorial of %d using iteration: %lld\n", num, factorial_iterative(num));
                break;
            case 3:
                printf("Factors of %d using recursion: ", num);
                factors_recursive(num, 1);
                printf("\n");
                break;
            case 4:
                printf("Factors of %d using iteration: ", num);
                factors_iterative(num);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to calculate factorial using recursion
long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

// Function to calculate factorial using iteration
long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to compute factors using recursion
void factors_recursive(int n, int i) {
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    factors_recursive(n, i + 1);
}

// Function to compute factors using iteration
void factors_iterative(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
}
/*
Output:
Enter a number: 5

Choose an operation:
1. Factorial using recursion
2. Factorial using iteration
3. Factors using recursion
4. Factors using iteration
5. Exit
Enter your choice: 1
Factorial of 5 using recursion: 120

Choose an operation:
1. Factorial using recursion
2. Factorial using iteration
3. Factors using recursion
4. Factors using iteration
5. Exit
Enter your choice: 2
Factorial of 5 using iteration: 120

Choose an operation:
1. Factorial using recursion
2. Factorial using iteration
3. Factors using recursion
4. Factors using iteration
5. Exit
Enter your choice: 3
Factors of 5 using recursion: 1 5

Choose an operation:
1. Factorial using recursion
2. Factorial using iteration
3. Factors using recursion
4. Factors using iteration
5. Exit
Enter your choice: 4
Factors of 5 using iteration: 1 5

Choose an operation:
1. Factorial using recursion
2. Factorial using iteration
3. Factors using recursion
4. Factors using iteration
5. Exit
Enter your choice: 5
Exiting the program.
*/