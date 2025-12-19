/*
Topic: Sequential (Linear) Search

Time Complexity:
Best Case: O(1)       → Element found at first position
Average Case: O(n)    → Element found in middle
Worst Case: O(n)      → Element found at last or not found

Space Complexity:
O(1) → Uses constant extra space
*/

#include <stdio.h>

int main()
{
    int arr[10], n, key, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found\n");

    return 0;
}

/*
Output:
Enter number of elements: 5
Enter elements:
10 25 30 45 50
Enter key to search: 25
Element found at index 1
*/