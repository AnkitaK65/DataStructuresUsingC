/*
Program 8: Write a C program to read and display a 2-D array (matrix).
*/

#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Output:
Enter rows and columns: 3 3
Enter elements:
1 2 3 4 5 6 7 8 9
Matrix:
1 2 3 
4 5 6 
7 8 9
*/