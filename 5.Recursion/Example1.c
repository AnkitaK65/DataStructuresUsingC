/*
Question: Write a recursive function to print numbers from 1 to N.
*/

#include <stdio.h>

void printNumbers(int n)
{
    if (n == 0) // Base case
        return;
    printNumbers(n - 1); // Recursive call (smaller problem)
    printf("%d ", n);    // Work after recursion
}

int main()
{
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Iterative way:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }

    printf("\nRecursive way:\n");
    printNumbers(n);

    printf("\n");
    return 0;
}

/*
Output:
Enter a number: 5
Iterative way:
1 2 3 4 5 
Recursive way:
1 2 3 4 5
*/