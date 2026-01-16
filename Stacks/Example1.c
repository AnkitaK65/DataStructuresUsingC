/*
Topic: Stack Implementation using Array

A stack follows the LIFO (Last In First Out) principle.
The element inserted last is removed first.

Operations implemented:
1. push(x)   - Insert an element into the stack
2. pop()     - Remove the top element from the stack
3. peek()    - View the top element without removing it
4. isEmpty() - Check if the stack is empty
5. isFull()  - Check if the stack is full
6. display() - Show all elements of the stack
*/

#include <stdio.h>

#define MAX 5   // Maximum size of the stack

// Global stack array and top pointer
int stack[MAX];
int top = -1;   // Initially, stack is empty

/*
-------------------------------------------------------
Function: isEmpty
Purpose : Check if the stack is empty
Returns : 1 if empty, 0 otherwise
-------------------------------------------------------
*/
int isEmpty() {
    return top == -1;
}

/*
-------------------------------------------------------
Function: isFull
Purpose : Check if the stack is full
Returns : 1 if full, 0 otherwise
-------------------------------------------------------
*/
int isFull() {
    return top == MAX - 1;
}

/*
-------------------------------------------------------
Function: push
Purpose : Insert an element into the stack
Argument: x - value to be inserted
-------------------------------------------------------
*/
void push(int x) {
    if (isFull())
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = x;
        printf("%d pushed into stack\n", x);
    }
}

/*
-------------------------------------------------------
Function: pop
Purpose : Remove the top element from the stack
-------------------------------------------------------
*/
void pop() {
    if (isEmpty())
        printf("Stack Underflow\n");
    else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

/*
-------------------------------------------------------
Function: peek
Purpose : View the top element of the stack without removing it
Returns : Top element if stack is not empty
-------------------------------------------------------
*/
void peek() {
    if (isEmpty())
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

/*
-------------------------------------------------------
Function: display
Purpose : Display all elements of the stack
-------------------------------------------------------
*/
void display() {
    if (isEmpty())
        printf("Stack is empty\n");
    else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    // Push elements into the stack
    push(10);
    push(20);
    push(30);

    // Display stack contents
    display();

    // Peek top element
    peek();

    // Pop one element from the stack
    pop();

    // Display stack after pop operation
    display();

    // Check if stack is empty or full
    if (isEmpty()) 
        printf("Stack is empty\n");
    if (isFull()) 
        printf("Stack is full\n");

    return 0;
}

/*
Output:
10 pushed into stack
20 pushed into stack
30 pushed into stack
Stack elements (top to bottom):
30
20
10
Top element: 30
Popped element: 30
Stack elements (top to bottom):
20
10
*/