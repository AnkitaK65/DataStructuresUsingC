/*
Topic: Two Stacks in a Single Array

Concept:
1. Stack1 grows from the left (index 0) towards right.
2. Stack2 grows from the right (index MAX-1) towards left.
3. Both stacks share the same array, utilizing memory efficiently.
4. Overflow occurs if the stacks meet in the middle.
5. Underflow occurs if pop is called on an empty stack.

Operations implemented:
1. push1(x) - Push element into Stack1
2. push2(x) - Push element into Stack2
3. pop1()   - Remove top element from Stack1
4. pop2()   - Remove top element from Stack2
5. display() - Display both stacks
*/

#include <stdio.h>

#define MAX 10   // Size of the array

int arr[MAX];    // Shared array for both stacks
int top1 = -1;   // Top pointer for Stack1
int top2 = MAX;  // Top pointer for Stack2

void push1(int x) {
    if (top1 < top2 - 1) {   // Check if space is available
        top1++;
        arr[top1] = x;
        printf("%d pushed into Stack1\n", x);
    } else {
        printf("Stack1 Overflow\n");
    }
}

void push2(int x) {
    if (top1 < top2 - 1) {   // Check if space is available
        top2--;
        arr[top2] = x;
        printf("%d pushed into Stack2\n", x);
    } else {
        printf("Stack2 Overflow\n");
    }
}

void pop1() {
    if (top1 == -1) {
        printf("Stack1 Underflow\n");
    } else {
        printf("Popped from Stack1: %d\n", arr[top1]);
        top1--;
    }
}

void pop2() {
    if (top2 == MAX) {
        printf("Stack2 Underflow\n");
    } else {
        printf("Popped from Stack2: %d\n", arr[top2]);
        top2++;
    }
}

void display() {
    printf("\nStack1 (top to bottom):\n");
    if (top1 == -1)
        printf("Stack1 is empty\n");
    else {
        for (int i = top1; i >= 0; i--)
            printf("%d ", arr[i]);
    }

    printf("\nStack2 (top to bottom):\n");
    if (top2 == MAX)
        printf("Stack2 is empty\n");
    else {
        for (int i = top2; i < MAX; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Push elements into Stack1
    push1(10);
    push1(20);

    // Push elements into Stack2
    push2(100);
    push2(200);

    // Display both stacks
    display();

    // Pop elements from both stacks
    pop1();
    pop2();

    // Display both stacks after pop
    display();

    return 0;
}

/*
Output:
10 pushed into Stack1
20 pushed into Stack1
100 pushed into Stack2
200 pushed into Stack2

Stack1 (top to bottom):
20 10 
Stack2 (top to bottom):
200 100 
Popped from Stack1: 20
Popped from Stack2: 200

Stack1 (top to bottom):
10 
Stack2 (top to bottom):
100 
*/