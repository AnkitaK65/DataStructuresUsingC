/*
Topic: Insertion Sort

Time Complexity:
Best Case: O(n)      → Already sorted
Average Case: O(n²)
Worst Case: O(n²)    → Reverse sorted

How Time Complexity is Calculated:
- Inner loop shifts elements
- Worst case shifts = 1 + 2 + ... + (n−1) ≈ n²/2

Space Complexity:
O(1)
*/

#include <stdio.h>

int main()
{
    int arr[10], n, i, key, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Output:
Enter number of elements: 10
Enter elements:
12 4 3 1 15 45 33 21 10 2
Sorted array:
1 2 3 4 10 12 15 21 33 45
*/