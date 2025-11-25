/*
Program 20: Write a C program to find the transpose of a sparse matrix using 3-tuple representation.
*/

#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of non-zero + 1: ");
    scanf("%d", &n);

    int t[n][3], tr[n][3];

    printf("Enter 3-tuple (row col val):\n");
    for(i=0;i<n;i++) {
        scanf("%d %d %d", &t[i][0], &t[i][1], &t[i][2]);
    }

    tr[0][0] = t[0][1];
    tr[0][1] = t[0][0];
    tr[0][2] = t[0][2];

    int k = 1;

    for(int col=0; col < t[0][1]; col++) {
        for(i = 1; i < n; i++) {
            if(t[i][1] == col) {
                tr[k][0] = t[i][1];
                tr[k][1] = t[i][0];
                tr[k][2] = t[i][2];
                k++;
            }
        }
    }

    printf("Transpose 3-Tuple:\n");
    for(i=0;i<n;i++) {
        printf("%d %d %d\n", tr[i][0], tr[i][1], tr[i][2]);
    }

    return 0;
}

/*
Output:
Enter number of non-zero + 1: 5
Enter 3-tuple (row col val):
3 3 4
0 0 1
1 1 7
2 0 12
2 2 45
Transpose 3-Tuple:
3 3 4
0 0 1
0 2 12
1 1 7
2 2 45
*/