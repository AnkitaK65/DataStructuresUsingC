/*
Program 11: Write a C program to print memory addresses of 2D array elements 
to demonstrate row-major and column-major storage.
*/

#include <stdio.h>

int main() {
    int a[3][3], i, j;

    printf("Enter 9 elements:\n");
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Memory addresses:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++) {
            printf("Address of a[%d][%d] = %p\n", i, j, &a[i][j]);
        }
    }

    return 0;
}

/*
Output:
Enter 9 elements:
1 2 3 4 5 6 7 8 9
Memory addresses:
Address of a[0][0] = 0x16dab2ab4
Address of a[0][1] = 0x16dab2ab8
Address of a[0][2] = 0x16dab2abc
Address of a[1][0] = 0x16dab2ac0
Address of a[1][1] = 0x16dab2ac4
Address of a[1][2] = 0x16dab2ac8
Address of a[2][0] = 0x16dab2acc
Address of a[2][1] = 0x16dab2ad0
Address of a[2][2] = 0x16dab2ad4
*/

/*
Memory increases first along columns inside the same row,
then moves to next row.
Memory Layout is Row-Major.
*/