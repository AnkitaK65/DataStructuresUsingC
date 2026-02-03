// ===============================
// SIMPLE QUEUE USING ARRAY
// FIFO: First In First Out
// Insertion at REAR, Deletion from FRONT
// ===============================

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = x;
    printf("Inserted: %d\n", x);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

/*
Sample Output:
1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 3
Queue is Empty

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 1
Enter value: 5
Inserted: 5

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 1
Enter value: 4
Inserted: 4

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 1
Enter value: 6
Inserted: 6

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 1
Enter value: 7
Inserted: 7

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 1
Enter value: 9
Inserted: 9

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 1
Enter value: 3
Queue Overflow

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 3
Queue elements: 5 4 6 7 9 

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 2
Deleted: 5

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 3
Queue elements: 4 6 7 9 

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 2
Deleted: 4

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 2
Deleted: 6

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 2
Deleted: 7

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 2
Deleted: 9

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 2
Queue Underflow

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 3
Queue is Empty

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter choice: 4
*/