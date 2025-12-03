/*
Example 21: Using calloc() for dynamic array allocation
------------------------------------------------------
Purpose:
- To demonstrate how calloc() allocates memory and initializes it to zero.

Notes:
1) malloc()
    - Syntax: ptr = (int*)malloc(n * sizeof(int));
    - Allocates dynamic memory but DOES NOT initialize values.
    - Default (garbage) values exist in allocated memory.

2) calloc()
    - Syntax: ptr = (int*)calloc(n, sizeof(int));
    - Allocates memory for multiple elements and initializes ALL values to 0.
    - Useful for arrays where initial values should be zero.

3) realloc()
    - Syntax: ptr = (int*)realloc(ptr, newSize);
    - Changes/Resizes previously allocated memory block using malloc/calloc.
    - May move data to a new location if required.
    - Used when array size needs to grow or shrink dynamically.
--------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5; // Total number of elements to store in array

    // Allocating memory using calloc (initializes all values to 0)
    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Values initialized by calloc:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); // All values will be 0

    // After using the memory, free it to avoid memory leak
    free(arr);

    return 0;
}

/*
Output:
Values initialized by calloc:
0 0 0 0 0 
*/