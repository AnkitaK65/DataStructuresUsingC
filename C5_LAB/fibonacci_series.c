/*
Question 11: Write a program to display the Fibonacci series:
(i) Using recursion
(ii) Using iteration
*/

#include <stdio.h>

// Function prototypes
void fibonacci_recursive(int n, int a, int b, int count);
void fibonacci_iterative(int n);

int main() {
    int n, choice;

    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of terms must be greater than zero.\n");
        return 1;
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. Fibonacci series using recursion\n");
        printf("2. Fibonacci series using iteration\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Fibonacci series using recursion: ");
                fibonacci_recursive(n, 0, 1, 0);
                printf("\n");
                break;
            case 2:
                printf("Fibonacci series using iteration: ");
                fibonacci_iterative(n);
                printf("\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display Fibonacci series using recursion
void fibonacci_recursive(int n, int a, int b, int count) {
    if (count == n) {
        return;
    }
    printf("%d ", a);
    fibonacci_recursive(n, b, a + b, count + 1);
}

// Function to display Fibonacci series using iteration
void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", a);
        } else if (i == 1) {
            printf("%d ", b);
        } else {
            next = a + b;
            printf("%d ", next);
            a = b;
            b = next;
        }
    }
}
/*
Output:
Enter the number of terms for the Fibonacci series: 10

Choose an operation:
1. Fibonacci series using recursion
2. Fibonacci series using iteration
3. Exit
Enter your choice: 1
Fibonacci series using recursion: 0 1 1 2 3 5 8 13 21 34

Choose an operation:
1. Fibonacci series using recursion
2. Fibonacci series using iteration
3. Exit
Enter your choice: 2
Fibonacci series using iteration: 0 1 1 2 3 5 8 13 21 34

Choose an operation:
1. Fibonacci series using recursion
2. Fibonacci series using iteration
3. Exit
Enter your choice: 3
Exiting the program.
*/