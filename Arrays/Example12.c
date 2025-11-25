/*
Program 12: Write a C program to print upper triangular matrix.
*/

#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n][n];
    printf("Enter elements:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Upper triangular matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i <= j) 
            {
                printf("%d ", a[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*
Output:
Enter size: 3
Enter elements:
1 2 3 4 5 6 7 8 9
Upper triangular matrix:
1 2 3 
0 5 6 
0 0 9
*/