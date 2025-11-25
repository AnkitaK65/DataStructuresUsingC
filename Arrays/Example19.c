/*
Program 19: Write a C program to reconstruct matrix from 3-tuple representation.
*/

#include <stdio.h>

int main() {
    int n, i, r, c;
    printf("Enter number of non-zero + 1: ");
    scanf("%d", &n);

    int t[n][3];
    printf("Enter 3-tuple (row col val):\n");
    for(i=0;i<n;i++) {
        scanf("%d %d %d", &t[i][0], &t[i][1], &t[i][2]);
    }

    r = t[0][0];
    c = t[0][1];
    int a[r][c];

    for(i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            a[i][j] = 0;
        }
    }

    for(i=1;i<n;i++) {
        a[t[i][0]][t[i][1]] = t[i][2];
    }

    printf("Reconstructed Matrix:\n");
    for(i=0;i<r;i++){
        for(int j=0;j<c;j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Output:
Enter number of non-zero + 1: 5
Enter 3-tuple (row col val):
3 3 4
0 0 1 
1 1 4
2 0 7
2 1 10
Reconstructed Matrix:
1 0 0 
0 4 0 
7 10 0
*/