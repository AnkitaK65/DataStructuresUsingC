/*
=========================================================
Topic: Dynamic Singly Linked List Using Arrays
=========================================================

Explanation:
- This program implements a singly linked list using arrays.
- Dynamic behavior is achieved using a FREE LIST.
- Nodes are NOT stored sequentially.
- The 'next' array stores the index of the next node.
- Deleted nodes are reused instead of wasting space.

Key Variables:
- data[MAX]     : stores data values
- next[MAX]     : stores index of next node
- head          : index of first node (-1 means empty list)
- freeHead      : index of first free node (free list)
*/

#include <stdio.h>
#define MAX 10
#define NULL_INDEX -1

int data[MAX];
int next[MAX];

int head = NULL_INDEX;      // start of linked list
int freeHead = 0;           // start of free list

/* Initialize free list */
void initialize() {
    for (int i = 0; i < MAX - 1; i++)
        next[i] = i + 1;
    next[MAX - 1] = NULL_INDEX;
}

/* Allocate a node from free list */
int allocateNode() {
    if (freeHead == NULL_INDEX) {
        printf("No free space available.\n");
        return NULL_INDEX;
    }
    int index = freeHead;
    freeHead = next[freeHead];
    return index;
}

/* Free a node and add it back to free list */
void freeNode(int index) {
    next[index] = freeHead;
    freeHead = index;
}

/* Insert at beginning */
void insertAtBeginning(int value) {
    int newNode = allocateNode();
    if (newNode == NULL_INDEX) return;

    data[newNode] = value;
    next[newNode] = head;
    head = newNode;
}

/* Insert at end */
void insertAtEnd(int value) {
    int newNode = allocateNode();
    if (newNode == NULL_INDEX) return;

    data[newNode] = value;
    next[newNode] = NULL_INDEX;

    if (head == NULL_INDEX) {
        head = newNode;
        return;
    }

    int temp = head;
    while (next[temp] != NULL_INDEX)
        temp = next[temp];

    next[temp] = newNode;
}

/*
Topic: Insert at Given Position (Dynamic Linked List using Arrays)

Explanation:
- Position starts from 1
- Uses free list for dynamic allocation
- Adjusts links, not array indices
*/

void insertAtPosition(int value, int pos) {
    int newNode, temp, prev;
    int i;

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    /* Allocate node from free list */
    if (freeHead == NULL_INDEX) {
        printf("Overflow! No free space.\n");
        return;
    }

    newNode = freeHead;
    freeHead = next[freeHead];

    data[newNode] = value;
    next[newNode] = NULL_INDEX;

    /* Case 1: Insert at beginning (pos = 1) */
    if (pos == 1) {
        next[newNode] = head;
        head = newNode;
        return;
    }

    /* Case 2: Insert at middle or end */
    temp = head;
    prev = NULL_INDEX;

    for (i = 1; i < pos && temp != NULL_INDEX; i++) {
        prev = temp;
        temp = next[temp];
    }

    if (prev == NULL_INDEX) {
        printf("Position out of range!\n");

        /* Return node back to free list */
        next[newNode] = freeHead;
        freeHead = newNode;
        return;
    }

    next[newNode] = temp;
    next[prev] = newNode;
}

/* Delete from beginning */
void deleteFromBeginning() {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }

    int temp = head;
    head = next[head];
    freeNode(temp);
}

/* Delete from end */
void deleteFromEnd() {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }

    if (next[head] == NULL_INDEX) {
        freeNode(head);
        head = NULL_INDEX;
        return;
    }

    int temp = head;
    while (next[next[temp]] != NULL_INDEX)
        temp = next[temp];

    freeNode(next[temp]);
    next[temp] = NULL_INDEX;
}

/* Delete by value */
void deleteByValue(int value) {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }

    if (data[head] == value) {
        deleteFromBeginning();
        return;
    }

    int temp = head;
    while (next[temp] != NULL_INDEX && data[next[temp]] != value)
        temp = next[temp];

    if (next[temp] == NULL_INDEX) {
        printf("Value not found.\n");
        return;
    }

    int del = next[temp];
    next[temp] = next[del];
    freeNode(del);
}

/* Search element */
void search(int value) {
    int temp = head, pos = 1;
    while (temp != NULL_INDEX) {
        if (data[temp] == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = next[temp];
        pos++;
    }
    printf("Value not found.\n");
}

/* Display list */
/* Display linked list AND array representation */
void display() {
    int i;

    /* Part 1: Linked List View */
    if (head == NULL_INDEX) {
        printf("Linked List is empty.\n");
    } else {
        int temp = head;
        printf("\nLinked List (Logical Order):\n");
        while (temp != NULL_INDEX) {
            printf("%d -> ", data[temp]);
            temp = next[temp];
        }
        printf("NULL\n");
    }

    /* Part 2: Array Representation */
    printf("\nArray Representation:\n");
    printf("Index : ");
    for (i = 0; i < MAX; i++)
        printf("%3d ", i);

    printf("\nData  : ");
    for (i = 0; i < MAX; i++)
        printf("%3d ", data[i]);

    printf("\nNext  : ");
    for (i = 0; i < MAX; i++)
        printf("%3d ", next[i]);

    printf("\nHead = %d, FreeHead = %d\n", head, freeHead);
}

/* Main */
int main() {
    int choice, value, pos;
    initialize();

    while (1) {
        printf("\n--- Dynamic Linked List Using Arrays ---\n");
        printf("1.Insert Begin  2.Insert End  3.Insert Position\n");
        printf("4.Delete Begin  5.Delete End  6.Delete By Value\n");
        printf("7.Display       8.Search      9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &value);
                    insertAtBeginning(value); break;
            case 2: printf("Value: "); scanf("%d", &value);
                    insertAtEnd(value); break;
            case 3: printf("Value & Position: ");
                    scanf("%d%d", &value, &pos);
                    insertAtPosition(value, pos); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: printf("Value: "); scanf("%d", &value);
                    deleteByValue(value); break;
            case 7: display(); break;
            case 8: printf("Value: "); scanf("%d", &value);
                    search(value); break;
            case 9: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

/*
Output:
--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7
Linked List is empty.

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :   0   0   0   0   0   0   0   0   0   0 
Next  :   1   2   3   4   5   6   7   8   9  -1 
Head = -1, FreeHead = 0

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 1
Value: 10

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 1
Value: 5

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 2
Value: 20

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 2
Value: 30

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
5 -> 10 -> 20 -> 30 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30   0   0   0   0   0   0 
Next  :   2   0   3  -1   5   6   7   8   9  -1 
Head = 1, FreeHead = 4

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 3
Value & Position: 25 3

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
5 -> 10 -> 25 -> 20 -> 30 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30  25   0   0   0   0   0 
Next  :   4   0   3  -1   2   6   7   8   9  -1 
Head = 1, FreeHead = 5

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 9
~/Work/RWC/DataStructuresUsingC/LinkedList ➤ gcc Example3.c
~/Work/RWC/DataStructuresUsingC/LinkedList ➤ ./a.out       

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 1
Value: 10

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 1
Value: 5

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 2
Value: 20

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 2
Value: 30

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
5 -> 10 -> 20 -> 30 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30   0   0   0   0   0   0 
Next  :   2   0   3  -1   5   6   7   8   9  -1 
Head = 1, FreeHead = 4

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 3
Value & Position: 25 3

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
5 -> 10 -> 25 -> 20 -> 30 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30  25   0   0   0   0   0 
Next  :   4   0   3  -1   2   6   7   8   9  -1 
Head = 1, FreeHead = 5

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 1
Value: 1

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 2
Value: 50

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
1 -> 5 -> 10 -> 25 -> 20 -> 30 -> 50 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30  25   1  50   0   0   0 
Next  :   4   0   3   6   2   1  -1   8   9  -1 
Head = 5, FreeHead = 7

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 6
Value: 5

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
1 -> 10 -> 25 -> 20 -> 30 -> 50 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30  25   1  50   0   0   0 
Next  :   4   7   3   6   2   0  -1   8   9  -1 
Head = 5, FreeHead = 1

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 4

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 5

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 7

Linked List (Logical Order):
10 -> 25 -> 20 -> 30 -> NULL

Array Representation:
Index :   0   1   2   3   4   5   6   7   8   9 
Data  :  10   5  20  30  25   1  50   0   0   0 
Next  :   4   7   3  -1   2   1   5   8   9  -1 
Head = 0, FreeHead = 6

--- Dynamic Linked List Using Arrays ---
1.Insert Begin  2.Insert End  3.Insert Position
4.Delete Begin  5.Delete End  6.Delete By Value
7.Display       8.Search      9.Exit
Enter choice: 9
*/