// ===============================
// PRIORITY QUEUE USING ARRAY
// Higher value = Higher priority
// Elements stored in descending order
// ===============================

#include <stdio.h>
#define MAX 5

int pq[MAX];
int size = 0;

// Insert element based on priority
/*
ALGORITHM: INSERT (Priority Queue)

1. Check if queue is full (size == MAX)
    → If yes, display "Priority Queue Full" and stop.
2. Start from last element (i = size - 1).
3. Shift elements to the right while:
    pq[i] < new element AND i >= 0
4. Insert new element at position i + 1.
5. Increment size by 1.
*/
void insert(int x) {
    int i;

    if (size == MAX) {
        printf("Priority Queue Full\n");
        return;
    }

    // Shift elements to maintain descending order
    for (i = size - 1; i >= 0 && pq[i] < x; i--) {
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = x;
    size++;

    printf("Inserted: %d\n", x);
}

// Delete highest priority element
/*
ALGORITHM: DELETE (Priority Queue)

1. Check if queue is empty (size == 0)
    → If yes, display "Priority Queue Empty" and stop.
2. The first element (index 0) has highest priority.
3. Display the deleted element.
4. Shift remaining elements one position to the left.
5. Decrement size by 1.
*/
void delete() {
    if (size == 0) {
        printf("Priority Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", pq[0]);

    for (int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

// Display queue
void display() {
    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
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
Output:
1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 1
Enter value: 10
Inserted: 10

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 1
Enter value: 2
Inserted: 2

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 3
Priority Queue: 10 2 

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 1
Enter value: 12
Inserted: 12

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 3
Priority Queue: 12 10 2 

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 2
Deleted: 12

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 3
Priority Queue: 10 2 

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 1
Enter value: 5
Inserted: 5

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 2
Deleted: 10

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 3
Priority Queue: 5 2 

1.Insert  2.Delete  3.Display  4.Exit
Enter choice: 4
*/