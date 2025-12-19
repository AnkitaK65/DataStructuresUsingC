/*
Topic: Bubble Sort

Time Complexity:
Best Case: O(n)
Average Case: O(n²)
Worst Case: O(n²)

How Time Complexity is Calculated:
- Two nested loops
- Total comparisons = n(n−1)/2 ≈ n²

Space Complexity:
O(1) → In-place sorting
*/

#include <stdio.h>

int main()
{
    int arr[10], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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