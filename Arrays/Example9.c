/*
Program 9: Write a C program to add two matrices.
*/

#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows & columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c], b[r][c], sum[r][c];

    printf("Enter first matrix:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter second matrix:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d",&b[i][j]);
        }
    }

    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            sum[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("Sum matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++) {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Output:
Enter rows & columns: 3 3
Enter first matrix:
1 2 3 4 5 6 7 8 9
Enter second matrix:
1 2 3 1 2 3 1 2 3
Sum matrix:
2 4 6 
5 7 9 
8 10 12 
*/