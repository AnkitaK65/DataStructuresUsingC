// ===============================
// DEQUE WITHOUT RESTRICTION
// Insert & Delete allowed at FRONT and REAR
// ===============================

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at front
void insertFront(int x) {
    if (front == 0) {
        printf("Overflow at front\n");
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
        printf("Overflow at rear\n");
        return;
    }

    if (front == -1)
        front = 0;

    deque[++rear] = x;
    printf("Inserted at rear: %d\n", x);
}

// Delete from front
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

// Delete from rear
void deleteRear() {
    if (rear == -1) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
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
        printf("\n1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit\n");
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
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

/*
Output:
1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 1
Enter value: 1
Inserted at front: 1

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 1
Enter value: 2
Overflow at front

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 2
Enter value: 2
Inserted at rear: 2

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 2
Enter value: 3
Inserted at rear: 3

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 2
Enter value: 4
Inserted at rear: 4

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 5
Deque elements: 1 2 3 4 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 2
Enter value: 5
Inserted at rear: 5

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 5
Deque elements: 1 2 3 4 5 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 2
Enter value: 6
Overflow at rear

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 3
Deleted from front: 1

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 5
Deque elements: 2 3 4 5 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 4
Deleted from rear: 5

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 5
Deque elements: 2 3 4 

1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit
Enter choice: 6
*/