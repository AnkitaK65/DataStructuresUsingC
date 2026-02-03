// ==========================================
// REVERSE A QUEUE USING RECURSION
// ==========================================
//
// NOTES:
// 1. Queue follows FIFO
// 2. Recursion can reverse the order by:
//    - Dequeue front element
//    - Recursively reverse the remaining queue
//    - Enqueue the removed element at the rear
//
// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)
// ==========================================

#include <stdio.h>
#define MAX 5

int q[MAX];
int front = -1, rear = -1;

// ENQUEUE
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    q[++rear] = x;
}

// DEQUEUE
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = q[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return value;
}

// DISPLAY QUEUE
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}

/*
ALGORITHM: REVERSE QUEUE USING RECURSION

Step 1: Check if queue is empty
        → If yes, return
Step 2: Dequeue front element and store it
Step 3: Recursively reverse the remaining queue
Step 4: Enqueue the stored element at the rear
Step 5: Base case ensures recursion stops at empty queue
*/
void reverseQueue() {
    if (front == -1)
        return;

    int x = dequeue();
    reverseQueue();
    enqueue(x);
}

// MAIN FUNCTION
int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                reverseQueue();
                printf("Queue reversed successfully\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

/*
Output:
1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 1

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 2

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 3

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 4

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 3
Queue elements: 1 2 3 4 

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 4
Queue reversed successfully

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 3
Queue elements: 4 3 2 1 

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 5
*/