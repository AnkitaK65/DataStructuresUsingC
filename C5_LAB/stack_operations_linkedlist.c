/*
 * Question 6: Perform Stack operations using Linked List implementation
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for stack nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize the stack (top pointer)
Node* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations using Linked List:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element is %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/*
Output:
Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
Stack is empty
Top element is -1

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Stack underflow

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 12
Pushed 12 onto the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 545
Pushed 545 onto the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 21
Pushed 21 onto the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 67
Pushed 67 onto the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 67 21 545 12

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 67 from the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
Top element is 21

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 21 545 12

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 21 from the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 545 12

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 545 from the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 12

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 15
Pushed 15 onto the stack

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 15 12

Stack Operations using Linked List:
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting...
*/