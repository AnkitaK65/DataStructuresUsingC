/*
================================================================
Topic: Doubly Linked List Using Arrays (Dynamic Implementation)
================================================================

Short Notes:
- This program implements a DOUBLY LINKED LIST using arrays.
- Three arrays are used:
    data[] : stores data values
    prev[] : stores index of previous node
    next[] : stores index of next node
- head stores index of first node.
- freeHead maintains a free list for dynamic allocation.
- -1 represents NULL.

Why this is dynamic?
- Nodes are taken from free list and returned after deletion.
- next[] and prev[] decide linkage, NOT array index order.

================================================================
*/

#include <stdio.h>

#define MAX 10
#define NULL_INDEX -1

int data[MAX];
int prev[MAX];
int next[MAX];

int head = NULL_INDEX;
int freeHead = 0;

/*
==============================================================
Initialize Free List
==============================================================
Steps:
1. Link all array indices as free nodes
2. freeHead points to first free index
*/
void init() {
    for (int i = 0; i < MAX - 1; i++) {
        next[i] = i + 1;
        prev[i] = NULL_INDEX;
    }
    next[MAX - 1] = NULL_INDEX;
    prev[MAX - 1] = NULL_INDEX;
}

/*
==============================================================
Insert at Beginning
==============================================================
*/
void insertAtBeginning(int value) {
    if (freeHead == NULL_INDEX) {
        printf("Overflow! No free space available.\n");
        return;
    }

    int newNode = freeHead;
    freeHead = next[freeHead];

    data[newNode] = value;
    prev[newNode] = NULL_INDEX;
    next[newNode] = head;

    if (head != NULL_INDEX)
        prev[head] = newNode;

    head = newNode;

    printf("✔ %d inserted at beginning.\n", value);
}

/*
==============================================================
Insert at End
==============================================================
*/
void insertAtEnd(int value) {
    if (freeHead == NULL_INDEX) {
        printf("Overflow! No free space available.\n");
        return;
    }

    int newNode = freeHead;
    freeHead = next[freeHead];

    data[newNode] = value;
    next[newNode] = NULL_INDEX;

    if (head == NULL_INDEX) {
        prev[newNode] = NULL_INDEX;
        head = newNode;
        printf("✔ %d inserted as first node.\n", value);
        return;
    }

    int temp = head;
    while (next[temp] != NULL_INDEX)
        temp = next[temp];

    next[temp] = newNode;
    prev[newNode] = temp;

    printf("✔ %d inserted at end.\n", value);
}

/*
==============================================================
Insert at Given Position (1-based index)
==============================================================
*/
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    if (freeHead == NULL_INDEX) {
        printf("Overflow! No free space available.\n");
        return;
    }

    int temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL_INDEX; i++)
        temp = next[temp];

    if (temp == NULL_INDEX) {
        printf("Position out of range!\n");
        return;
    }

    int newNode = freeHead;
    freeHead = next[freeHead];

    data[newNode] = value;
    next[newNode] = next[temp];
    prev[newNode] = temp;

    if (next[temp] != NULL_INDEX)
        prev[next[temp]] = newNode;

    next[temp] = newNode;

    printf("✔ %d inserted at position %d.\n", value, pos);
}

/*
==============================================================
Delete from Beginning
==============================================================
*/
void deleteFromBeginning() {
    if (head == NULL_INDEX) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int temp = head;
    head = next[head];

    if (head != NULL_INDEX)
        prev[head] = NULL_INDEX;

    next[temp] = freeHead;
    freeHead = temp;

    printf("✔ Node deleted from beginning.\n");
}

/*
==============================================================
Delete from End
==============================================================
*/
void deleteFromEnd() {
    if (head == NULL_INDEX) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int temp = head;
    while (next[temp] != NULL_INDEX)
        temp = next[temp];

    if (prev[temp] != NULL_INDEX)
        next[prev[temp]] = NULL_INDEX;
    else
        head = NULL_INDEX;

    next[temp] = freeHead;
    freeHead = temp;

    printf("✔ Node deleted from end.\n");
}

/*
==============================================================
Delete by Value
==============================================================
*/
void deleteByValue(int value) {
    int temp = head;

    while (temp != NULL_INDEX && data[temp] != value)
        temp = next[temp];

    if (temp == NULL_INDEX) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (prev[temp] != NULL_INDEX)
        next[prev[temp]] = next[temp];
    else
        head = next[temp];

    if (next[temp] != NULL_INDEX)
        prev[next[temp]] = prev[temp];

    next[temp] = freeHead;
    freeHead = temp;

    printf("✔ Value %d deleted successfully.\n", value);
}

/*
==============================================================
Search Operation
==============================================================
*/
void search(int value) {
    int temp = head, pos = 1;

    while (temp != NULL_INDEX) {
        if (data[temp] == value) {
            printf("✔ Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = next[temp];
        pos++;
    }

    printf("Value %d not found in list.\n", value);
}

/*
==============================================================
Display Function
==============================================================
*/
void display() {
    int temp = head;

    printf("\nLinked List (Forward Traversal):\nNULL <-> ");
    while (temp != NULL_INDEX) {
        printf("%d <-> ", data[temp]);
        temp = next[temp];
    }
    printf("NULL\n");

    printf("\nArray Representation:\n");
    printf("Index: ");
    for (int i = 0; i < MAX; i++) printf("%3d ", i);

    printf("\nData : ");
    for (int i = 0; i < MAX; i++) printf("%3d ", data[i]);

    printf("\nPrev : ");
    for (int i = 0; i < MAX; i++) printf("%3d ", prev[i]);

    printf("\nNext : ");
    for (int i = 0; i < MAX; i++) printf("%3d ", next[i]);

    printf("\nHead = %d, FreeHead = %d\n", head, freeHead);
}

/*
==============================================================
Main Function (Menu Driven)
==============================================================
*/
int main() {
    int choice, value, pos;
    init();

    while (1) {
        printf("\n=========== MENU ===========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/*
Output:
=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 8

Linked List (Forward Traversal):
NULL <-> NULL

Array Representation:
Index:   0   1   2   3   4   5   6   7   8   9 
Data :   0   0   0   0   0   0   0   0   0   0 
Prev :  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1 
Next :   1   2   3   4   5   6   7   8   9  -1 
Head = -1, FreeHead = 0

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 1
Enter value to insert at beginning: 10
✔ 10 inserted at beginning.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 1
Enter value to insert at beginning: 5
✔ 5 inserted at beginning.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 2
Enter value to insert at end: 20
✔ 20 inserted at end.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 2
Enter value to insert at end: 30
✔ 30 inserted at end.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 3
Enter value: 15
Enter position (1-based): 3
✔ 15 inserted at position 3.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 8

Linked List (Forward Traversal):
NULL <-> 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

Array Representation:
Index:   0   1   2   3   4   5   6   7   8   9 
Data :  10   5  20  30  15   0   0   0   0   0 
Prev :   1  -1   4   2   0  -1  -1  -1  -1  -1 
Next :   4   0   3  -1   2   6   7   8   9  -1 
Head = 1, FreeHead = 5

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 4
✔ Node deleted from beginning.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 5
✔ Node deleted from end.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 6
Enter value to delete: 15
✔ Value 15 deleted successfully.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 8

Linked List (Forward Traversal):
NULL <-> 10 <-> 20 <-> NULL

Array Representation:
Index:   0   1   2   3   4   5   6   7   8   9 
Data :  10   5  20  30  15   0   0   0   0   0 
Prev :  -1  -1   0   2   0  -1  -1  -1  -1  -1 
Next :   2   5  -1   1   3   6   7   8   9  -1 
Head = 0, FreeHead = 4

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 7
Enter value to search: 20
✔ Value 20 found at position 2.

=========== MENU ===========
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete by Value
7. Search
8. Display
9. Exit
Enter your choice: 9
Exiting program...
*/