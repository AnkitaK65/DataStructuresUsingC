/*
Question: Solve Tower of Hanoi problem using recursion.
*/

#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);   // Move n-1 disks to aux
    printf("Move disk %d from %c to %c\n", n, from, to); // Move nth disk
    towerOfHanoi(n-1, aux, to, from);   // Move n-1 disks to destination
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

/*

Output:
Enter number of disks: 3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C

*/