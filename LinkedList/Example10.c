/* ============================================================
    Topic: Stack Using Singly Linked List

    Principle: LIFO (Last In First Out)

    Operations:
    1. Push
    2. Pop
    3. Peek
    4. Display
    5. isEmpty
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* ================= NODE STRUCTURE ================= */
struct Node {
    int data;
    struct Node* next;
};

/* ================= STACK TOP ================= */
struct Node* top = NULL;

/* ================= PUSH ================= */
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow! Memory full.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d into stack.\n", value);
}

/* ================= POP ================= */
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

/* ================= PEEK ================= */
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

/* ================= isEmpty ================= */
void isEmpty() {
    if (top == NULL)
        printf("Stack is Empty.\n");
    else
        printf("Stack is Not Empty.\n");
}

/* ================= DISPLAY ================= */
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;

    printf("\nStack Elements (Top to Bottom):\n");

    while (temp != NULL) {
        printf("| %d |\n", temp->data);
        printf("-----\n");
        temp = temp->next;
    }
}

/* ================= MAIN ================= */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Using Singly Linked List ---\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.isEmpty\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

/*
Output:
--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 4
Stack is empty.

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to push: 10
Pushed 10 into stack.

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to push: 20
Pushed 20 into stack.

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to push: 30
Pushed 30 into stack.

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 4

Stack Elements (Top to Bottom):
| 30 |
-----
| 20 |
-----
| 10 |
-----

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 3
Top element: 30

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Popped element: 30

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Popped element: 20

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 4

Stack Elements (Top to Bottom):
| 10 |
-----

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 5
Stack is Not Empty.

--- Stack Using Singly Linked List ---
1.Push
2.Pop
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 6
*/