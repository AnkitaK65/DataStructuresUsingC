/*
Program 17: Write a C program to check whether a matrix is sparse.
*/

#include <stdio.h>

int main() {
    int r, c, i, j, count = 0;
    printf("Enter rows & columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];
    printf("Enter elements:\n");

    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d",&a[i][j]);
            if(a[i][j] == 0) {
                count++;
            }
        }
    }

    if(count > (r*c)/2) {
        printf("Sparse matrix.\n");
    }else {
        printf("Not a sparse matrix.\n");
    }

    return 0;
}

/*
Output:
Enter rows & columns: 5 5
Enter elements:
1 0 0 0 1
0 0 0 1 1
0 1 0 1 0
0 0 0 1 1
1 0 0 1 0
Sparse matrix.
*/