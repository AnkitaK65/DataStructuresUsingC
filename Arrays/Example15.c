/*
Program 15: Write a C program to create a dynamic array using malloc().
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    printf("Enter elements:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    printf("Dynamic array:\n");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

    free(arr);
    return 0;
}

/*
Output:
Enter size: 3
Enter elements:
1 2 3
Dynamic array:
1 2 3
*/