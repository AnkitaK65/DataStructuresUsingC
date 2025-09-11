/*
Question: Write a recursive function to print numbers from 1 to N.
*/

#include <stdio.h>

void printNumbers(int n)
{
    if (n == 0) // Base case
        return;

    printNumbers(n - 1); // Recursive call (smaller problem)

    // By default, output is buffered:
    // - In an IDE debugger (VS Code, CLion, CodeBlocks), stdout is often line-buffered or fully buffered.
    // - That means values may be stored in memory and only appear all at once
    //   after a newline '\n' or when the program finishes.
    printf("%d ", n); // Works after recursion 

    // To see each value appear immediately during debugging:
    // 1. Comment out the above line.
    // 2. Uncomment the next line and add a breakpoint here.
    // 3. Debug the program, step over -> each number prints individually.
    // printf("%d\n", n);
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
Output Example:
Enter a number: 5
Iterative way:
1 2 3 4 5 
Recursive way:
1 2 3 4 5
*/
