/*
Question: Demonstrate how recursion uses function call stack.
Aim: To visualize what goes behind recursion.
*/

#include <stdio.h>

void demoStack(int n)
{
    printf("Entering function with n = %d\n", n);

    if (n > 0)
        demoStack(n - 1); // Recursive call

    printf("Exiting function with n = %d\n", n);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    demoStack(n);
    return 0;
}

/*

OUtput:
Enter a number: 5
Entering function with n = 5
Entering function with n = 4
Entering function with n = 3
Entering function with n = 2
Entering function with n = 1
Entering function with n = 0
Exiting function with n = 0
Exiting function with n = 1
Exiting function with n = 2
Exiting function with n = 3
Exiting function with n = 4
Exiting function with n = 5

*/