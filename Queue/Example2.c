// ===============================
// CIRCULAR QUEUE USING ARRAY
// Solves space wastage of simple queue
// FIFO: First In First Out
// ===============================

#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

// Insert element
void enqueue(int x) {
    // Queue full condition
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Full\n");
        return;
    }

    // First insertion
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
    printf("Inserted: %d\n", x);
}

// Delete element
void dequeue() {
    // Queue empty condition
    if (front == -1) {
        printf("Circular Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    // Reset when last element removed
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

// Display elements
void display() {
    int i;

    if (front == -1) {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter your choice: ");
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
Enter your choice: 1
Enter value: 12
Inserted: 12

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 1
Enter value: 2
Inserted: 2

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 1
Enter value: 3
Inserted: 3

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 1
Enter value: 4
Inserted: 4

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 1
Enter value: 5
Inserted: 5

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 1
Enter value: 6
Circular Queue Full

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 2
Deleted: 12

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 3
Circular Queue elements: 2 3 4 5 

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 1
Enter value: 1
Inserted: 1

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 3
Circular Queue elements: 2 3 4 5 1 

1.Enqueue  2.Dequeue  3.Display  4.Exit
Enter your choice: 4
*/