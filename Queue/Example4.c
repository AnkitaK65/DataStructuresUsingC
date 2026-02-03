// ===============================
// OUTPUT RESTRICTED DEQUE
// Insertion allowed at FRONT and REAR
// Deletion allowed ONLY at FRONT
// ===============================

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at front
    // Insertion at front means moving left
    // But index 0 is the extreme left
    // There is no space before index 0
void insertFront(int x) {
    if (front == 0) {
        printf("No space at front\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        front--;

    deque[front] = x;
    printf("Inserted at front: %d\n", x);
}

// Insert at rear
void insertRear(int x) {
    if (rear == MAX - 1) {
        printf("Deque Full\n");
        return;
    }

    if (front == -1)
        front = 0;

    deque[++rear] = x;
    printf("Inserted at rear: %d\n", x);
}

// Delete only from front
void deleteFront() {
    if (front == -1) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// Display deque
void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                display();
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
1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 1
Enter value: 1
Inserted at front: 1

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 1
Enter value: 2
No space at front

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 2
Enter value: 3
Inserted at rear: 3

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 4
Deque elements: 1 3 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 2
Enter value: 4
Inserted at rear: 4

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 4
Deque elements: 1 3 4 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 3
Deleted from front: 1

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 4
Deque elements: 3 4 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 1
Enter value: 1
Inserted at front: 1

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 4
Deque elements: 1 3 4 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Display  5.Exit
Enter choice: 5
*/