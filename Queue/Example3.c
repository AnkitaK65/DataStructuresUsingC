// ===============================
// INPUT RESTRICTED DEQUE
// Insertion allowed ONLY at REAR
// Deletion allowed at FRONT and REAR
// ===============================

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

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
        printf("\n1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 2:
                deleteFront();
                break;

            case 3:
                deleteRear();
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
Sample Output:
1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 1
Enter value: 1
Inserted at rear: 1

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 1
Enter value: 2
Inserted at rear: 2

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 1
Enter value: 3
Inserted at rear: 3

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 4
Deque elements: 1 2 3 

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 2
Deleted from front: 1

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 3
Deleted from rear: 3

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 4
Deque elements: 2 

1.Insert Rear  2.Delete Front  3.Delete Rear  4.Display  5.Exit
Enter choice: 5
*/