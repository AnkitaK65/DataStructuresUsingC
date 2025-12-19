/*
Topic: Binary Search (Array must be sorted)

Time Complexity:
Best Case: O(1)
Average Case: O(log n)
Worst Case: O(log n)

How Time Complexity is Calculated:
- Array is divided into half each time.
- Number of comparisons = log₂(n)

Space Complexity:
O(1) → Iterative version
*/

#include <stdio.h>

int main()
{
    int arr[10], n, key, low, high, mid, found = 0;

    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found == 0)
        printf("Element not found\n");

    return 0;
}

/*
Output:
Enter number of elements (sorted): 10
Enter sorted elements:
1 2 3 4 10 12 15 21 33 45                                 
Enter key to search: 15
Element found at index 6
*/