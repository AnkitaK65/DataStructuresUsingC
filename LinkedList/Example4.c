/*
=========================================================
Topic: Doubly Linked List – Complete Implementation in C
=========================================================

Short Notes:
- A Doubly Linked List is a linear data structure where each node
    contains three parts:
    1. Pointer to previous node
    2. Data
    3. Pointer to next node
- Traversal is possible in both forward and backward directions.
- Dynamic memory allocation is used (malloc / free).
- Insertion and deletion are easier compared to singly linked list
    because previous node address is available.

Node Structure:
---------------------------------------------------------
| prev | data | next |
---------------------------------------------------------

NULL indicates no previous or next node.
*/

/* Required header files */
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Global head pointer */
struct Node *head = NULL;

/*
=========================================================
Function: Create New Node
=========================================================
*/
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*
=========================================================
Insertion Operations
=========================================================

Cases:
1. Insert at beginning
2. Insert at end
3. Insert at specific position
*/

/* Insert at Beginning */
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    head = newNode;
}

/* Insert at End */
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* Insert at Given Position (1-based index) */
void insertAtPosition(int value, int pos) {
    int i;
    struct Node* temp = head;

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/*
=========================================================
Deletion Operations
=========================================================

Cases:
1. Delete from beginning
2. Delete from end
3. Delete from specific position
4. Delete by value
*/

/* Delete from Beginning */
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

/* Delete from End */
void deleteFromEnd() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

/* Delete from Given Position */
void deleteFromPosition(int pos) {
    int i;
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

/* Delete by Value */
void deleteByValue(int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (temp == head) {
        deleteFromBeginning();
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

/*
=========================================================
Search Operation
=========================================================
*/
void search(int value) {
    int pos = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value not found!\n");
}

/*
=========================================================
Display Operations
=========================================================
*/

/* Print Forward */
void displayForward() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Forward: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Print Backward */
void displayBackward() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

/*
=========================================================
Main Function – Menu Driven
=========================================================
*/
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Delete by Value\n");
        printf("8. Search\n");
        printf("9. Display Forward\n");
        printf("10. Display Backward\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;

            case 7:
                printf("Enter value: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 9:
                displayForward();
                break;

            case 10:
                displayBackward();
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*
Output:
--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
List is empty!

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 1
Enter value: 10

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 1
Enter value: 5

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 2
Enter value: 20

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 2
Enter value: 30

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 5 <-> 10 <-> 20 <-> 30 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 3
Enter value and position: 15 3

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 4

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 5

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 10 <-> 15 <-> 20 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 2
Enter value: 30

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 2
Enter value: 40

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 2
Enter value: 50

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 10 <-> 15 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 6
Enter position: 2

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 7
Enter value: 15
Value not found!

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 7
Enter value: 30

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 8
Enter value to search: 40
Value 40 found at position 3

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 9
Forward: NULL <-> 10 <-> 20 <-> 40 <-> 50 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 10
Backward: NULL <-> 50 <-> 40 <-> 20 <-> 10 <-> NULL

--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Delete by Value
8. Search
9. Display Forward
10. Display Backward
11. Exit
Enter choice: 11
*/