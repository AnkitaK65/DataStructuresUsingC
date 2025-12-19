/*
Topic: Selection Sort

Time Complexity:
Best / Average / Worst Case: O(n²)

Space Complexity:
O(1) → In-place sorting
*/

#include <stdio.h>

int main()
{
    int arr[10], n, i, j, min, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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