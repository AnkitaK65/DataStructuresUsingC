/* ============================================================
    Topic: Queue Using Singly Linked List

    Principle: FIFO (First In First Out)

    Operations:
    1. Enqueue
    2. Dequeue
    3. Peek (Front element)
    4. Display
    5. isEmpty

    // Best choice to implement a circular queue is a circular linked list, because the last node naturally points back to the first node (rear->next = front).

   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* ================= NODE STRUCTURE ================= */
struct Node {
    int data;
    struct Node* next;
};

/* ================= FRONT AND REAR ================= */
struct Node* front = NULL;
struct Node* rear = NULL;

/* ================= ENQUEUE ================= */
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow! Memory full.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  // Queue empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d into queue.\n", value);
}

/* ================= DEQUEUE ================= */
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", front->data);

    front = front->next;

    if (front == NULL)  // If queue becomes empty
        rear = NULL;

    free(temp);
}

/* ================= PEEK ================= */
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

/* ================= isEmpty ================= */
void isEmpty() {
    if (front == NULL)
        printf("Queue is Empty.\n");
    else
        printf("Queue is Not Empty.\n");
}

/* ================= DISPLAY ================= */
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;

    printf("\nQueue Elements (Front to Rear):\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* ================= MAIN ================= */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.isEmpty\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
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
--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 4
Queue is empty.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to enqueue: 10
Enqueued 10 into queue.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to enqueue: 20
Enqueued 20 into queue.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to enqueue: 30
Enqueued 30 into queue.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 1
Enter value to enqueue: 40
Enqueued 40 into queue.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 4

Queue Elements (Front to Rear):
10 -> 20 -> 30 -> 40 -> NULL

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 3
Front element: 10

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Dequeued element: 10

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Dequeued element: 20

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 4

Queue Elements (Front to Rear):
30 -> 40 -> NULL

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 5
Queue is Not Empty.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Dequeued element: 30

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Dequeued element: 40

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 2
Queue Underflow! Queue is empty.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 5
Queue is Empty.

--- Queue Using Linked List ---
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.isEmpty
6.Exit
Enter choice: 6
*/