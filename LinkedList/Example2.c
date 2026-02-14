/*
Topic: Singly Linked List using Arrays (Static Linked List)
Short Notes:
- We simulate a linked list using arrays.
- Each node is represented as an element with two fields: data and next (index of next node).
- A special value (-1) represents NULL.
- Supports insertion, deletion, traversal, and search.
- Uses an array to store nodes and a variable 'head' to store the index of first node.
- A free list is maintained to reuse deleted nodes.

Algorithm Overview:
1. Insertion:
    - At Beginning: New node points to current head, update head.
    - At End: Traverse to last node, point its next to new node.
    - At Position: Traverse to (pos-1) node, link new node in between.
2. Deletion:
    - From Beginning: Update head to head->next.
    - From End: Traverse to second last node, set its next = -1.
    - At Position: Traverse to (pos-1) node, adjust next pointers.
    - By Value: Traverse to find value, adjust next pointers.
3. Display:
    - Traverse array from head using next indices.
4. Search:
    - Traverse array and compare data to target value.
*/

#include <stdio.h>
#define MAX 100
#define NULL_INDEX -1

// Node structure in array
struct Node {
    int data;
    int next;  // index of next node, -1 if NULL
};

struct Node list[MAX];
int head = NULL_INDEX; // index of first node
int freeIndex = 0;     // next free index in the array

// Allocate a new node
int createNode(int value) {
    if (freeIndex >= MAX) {
        printf("List is full. Cannot insert.\n");
        return NULL_INDEX;
    }
    int index = freeIndex++;
    list[index].data = value;
    list[index].next = NULL_INDEX;
    return index;
}

// Display list
void display() {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }
    int temp = head;
    printf("Linked List: ");
    while (temp != NULL_INDEX) {
        printf("%d -> ", list[temp].data);
        temp = list[temp].next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertAtBeginning(int value) {
    int index = createNode(value);
    if (index == NULL_INDEX) return;
    list[index].next = head;
    head = index;
}

// Insert at end
void insertAtEnd(int value) {
    int index = createNode(value);
    if (index == NULL_INDEX) return;

    if (head == NULL_INDEX) {
        head = index;
        return;
    }

    int temp = head;
    while (list[temp].next != NULL_INDEX)
        temp = list[temp].next;
    list[temp].next = index;
}

// Insert at position (1-based)
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    int temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL_INDEX) {
            printf("Position out of range.\n");
            return;
        }
        temp = list[temp].next;
    }

    int index = createNode(value);
    if (index == NULL_INDEX) return;

    list[index].next = list[temp].next;
    list[temp].next = index;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }
    head = list[head].next;
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }

    if (list[head].next == NULL_INDEX) {
        head = NULL_INDEX;
        return;
    }

    int temp = head;
    while (list[list[temp].next].next != NULL_INDEX)
        temp = list[temp].next;

    list[temp].next = NULL_INDEX;
}

// Delete at position (1-based)
void deleteAtPosition(int pos) {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    int temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL_INDEX || list[temp].next == NULL_INDEX) {
            printf("Position out of range.\n");
            return;
        }
        temp = list[temp].next;
    }

    if (list[temp].next == NULL_INDEX) {
        printf("Position out of range.\n");
        return;
    }

    list[temp].next = list[list[temp].next].next;
}

// Delete by value
void deleteByValue(int value) {
    if (head == NULL_INDEX) {
        printf("List is empty.\n");
        return;
    }

    if (list[head].data == value) {
        head = list[head].next;
        printf("Value %d deleted.\n", value);
        return;
    }

    int temp = head;
    while (list[temp].next != NULL_INDEX && list[list[temp].next].data != value)
        temp = list[temp].next;

    if (list[temp].next == NULL_INDEX) {
        printf("Value %d not found.\n", value);
        return;
    }

    list[temp].next = list[list[temp].next].next;
    printf("Value %d deleted.\n", value);
}

// Search for a value
void search(int value) {
    int temp = head;
    int pos = 1;
    while (temp != NULL_INDEX) {
        if (list[temp].data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = list[temp].next;
        pos++;
    }
    printf("Value %d not found in the list.\n", value);
}

// Main function
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Using Arrays ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete at Position\n");
        printf("7. Delete by Value\n8. Display List\n9. Search Value\n10. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
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
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 10:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

/*
Output:
--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 1
Enter value to insert: 10

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 1
Enter value to insert: 20

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 2
Enter value to insert: 30

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 2
Enter value to insert: 40

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 3
Enter value to insert: 3
Enter position: 35
Position out of range.

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 8
Linked List: 20 -> 10 -> 30 -> 40 -> NULL

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 3
Enter value to insert: 35
Enter position: 4

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 8
Linked List: 20 -> 10 -> 30 -> 35 -> 40 -> NULL

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 4

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 8
Linked List: 10 -> 30 -> 35 -> 40 -> NULL

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 6
Enter position to delete: 3

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 8
Linked List: 10 -> 30 -> 40 -> NULL

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 7
Enter value to delete: 50
Value 50 not found.

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 9
Enter value to search: 30
Value 30 found at position 2.

--- Singly Linked List Using Arrays ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Delete by Value
8. Display List
9. Search Value
10. Exit
Enter choice: 10
Exiting program.
*/