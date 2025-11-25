/*
Program 18: Write a C program to convert a sparse matrix into 3-tuple representation.
*/

#include <stdio.h>

int main() {
    int r, c, i, j, count = 0;
    printf("Enter rows & columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c], t[100][3];

    printf("Enter matrix:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d",&a[i][j]);
        }
    }

    t[0][0] = r;
    t[0][1] = c;

    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            if(a[i][j] != 0) {
                count++;
                t[count][0] = i;
                t[count][1] = j;
                t[count][2] = a[i][j];
            }
        }
    }

    t[0][2] = count;

    printf("3-Tuple Form:\n");
    for(i=0;i<=count;i++) {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }

    return 0;
}

/*
Output:
Enter rows & columns: 3 3
Enter matrix:
1 0 0
0 1 0
3 8 0
3-Tuple Form:
3 3 4
0 0 1
1 1 1
2 0 3
2 1 8
*/