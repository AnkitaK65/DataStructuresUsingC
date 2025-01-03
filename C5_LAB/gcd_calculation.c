/*
Question 12: Write a program to calculate the GCD of two numbers:
(i) Using recursion
(ii) Without recursion
*/

#include <stdio.h>

// Function prototypes
int gcd_recursive(int a, int b);
int gcd_non_recursive(int a, int b);

int main() {
    int num1, num2, choice, result;

    printf("Enter two numbers to calculate their GCD: ");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0) {
        printf("Both numbers must be greater than zero.\n");
        return 1;
    }

    do {
        printf("\nChoose an operation:\n");
        printf("1. GCD using recursion\n");
        printf("2. GCD without recursion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = gcd_recursive(num1, num2);
                printf("GCD (using recursion) of %d and %d is: %d\n", num1, num2, result);
                break;
            case 2:
                result = gcd_non_recursive(num1, num2);
                printf("GCD (without recursion) of %d and %d is: %d\n", num1, num2, result);
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

// Function to calculate GCD using recursion
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

// Function to calculate GCD without recursion
int gcd_non_recursive(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
/*
Output:
Enter two numbers to calculate their GCD: 12 18

Choose an operation:
1. GCD using recursion
2. GCD without recursion
3. Exit
Enter your choice: 1
GCD (using recursion) of 12 and 18 is: 6

Choose an operation:
1. GCD using recursion
2. GCD without recursion
3. Exit
Enter your choice: 2
GCD (without recursion) of 12 and 18 is: 6

Choose an operation:
1. GCD using recursion
2. GCD without recursion
3. Exit
Enter your choice: 3
Exiting the program.
*/