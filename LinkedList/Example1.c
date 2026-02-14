/*
Topic: Singly Linked List – Full Operations
Short Notes:
- A linked list is a self-referential data structure with nodes containing data and pointer to next.
- Singly linked list connects nodes in one direction.
- Dynamic memory allocation (malloc) is used to create nodes at runtime.
- Supports insertion, deletion, traversal, and search.
- Insertion and deletion can be at start, end, specific position, or by value.

Algorithms:

1. Insertion:
    a) At Beginning:
        1. Create new node.
        2. Point new node's next to head.
        3. Update head to new node.
    b) At End:
        1. Create new node.
        2. If list empty, make head = new node.
        3. Else traverse to last node.
        4. Link last node's next to new node.
    c) At Position:
        1. Create new node.
        2. Traverse to (position-1) node.
        3. Link new node in between.

2. Deletion:
    a) From Beginning:
        1. Update head = head->next.
        2. Free old head.
    b) From End:
        1. Traverse to second-last node.
        2. Set its next = NULL.
        3. Free last node.
    c) From Position:
        1. Traverse to previous node.
        2. Adjust pointers to skip node.
        3. Free memory.
    d) By Value:
        1. Traverse to find node with the value.
        2. Adjust previous node's next pointer.
        3. Free memory of deleted node.

3. Display:
    - Traverse from head to NULL and print data.

4. Search:
    - Traverse and compare each node with target value.
    - Return position if found.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Insert at position (1-based index)
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    if (pos == 1) return insertAtBeginning(head, value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range.\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete at position (1-based index)
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of range.\n");
            return head;
        }
        temp = temp->next;
    }

    struct Node* del = temp->next;
    if (del == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    temp->next = del->next;
    free(del);
    return head;
}

// Delete by value
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head has the value
    if (temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Value %d deleted.\n", value);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Value %d deleted.\n", value);
    return head;
}

// Search for a value
void search(struct Node* head, int value) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", value);
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete at Position\n");
        printf("7. Delete by Value\n8. Display List\n9. Search Value\n10. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteByValue(head, value);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 10:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

/*
Output:
1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 1

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 2

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 3

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 1
Enter value: 4

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 3
Queue elements: 1 2 3 4 

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 4
Queue reversed successfully

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 3
Queue elements: 4 3 2 1 

1.Enqueue  2.Dequeue  3.Display  4.Reverse  5.Exit
Enter choice: 5
~/Work/RWC/DataStructuresUsingC/Queue ➤ cd..
zsh: command not found: cd..
~/Work/RWC/DataStructuresUsingC/Queue ➤ cd ..
~/Work/RWC/DataStructuresUsingC ➤ cd LinkedList
~/Work/RWC/DataStructuresUsingC/LinkedList ➤ gcc Example1.c
~/Work/RWC/DataStructuresUsingC/LinkedList ➤ ./a.out       

--- Singly Linked List Operations ---
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
Enter value to insert: 1

--- Singly Linked List Operations ---
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
Enter value to insert: 0

--- Singly Linked List Operations ---
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
Enter value to insert: 3

--- Singly Linked List Operations ---
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
Linked List: 0 -> 1 -> 3 -> NULL

--- Singly Linked List Operations ---
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
Enter value to insert: 2
Enter position: 3

--- Singly Linked List Operations ---
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
Linked List: 0 -> 1 -> 2 -> 3 -> NULL

--- Singly Linked List Operations ---
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

--- Singly Linked List Operations ---
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
Linked List: 1 -> 2 -> 3 -> NULL

--- Singly Linked List Operations ---
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
Enter choice: 5

--- Singly Linked List Operations ---
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
Linked List: 1 -> 2 -> NULL

--- Singly Linked List Operations ---
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
Enter value to insert: 0

--- Singly Linked List Operations ---
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
Enter value to insert: 3

--- Singly Linked List Operations ---
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
Linked List: 0 -> 1 -> 2 -> 3 -> NULL

--- Singly Linked List Operations ---
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

--- Singly Linked List Operations ---
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
Linked List: 0 -> 1 -> 3 -> NULL

--- Singly Linked List Operations ---
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
Enter value to insert: 5

--- Singly Linked List Operations ---
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
Enter value to insert: 7

--- Singly Linked List Operations ---
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
Enter value to insert: 9

--- Singly Linked List Operations ---
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
Linked List: 0 -> 1 -> 3 -> 5 -> 7 -> 9 -> NULL

--- Singly Linked List Operations ---
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
Enter value to delete: 7
Value 7 deleted.

--- Singly Linked List Operations ---
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
Linked List: 0 -> 1 -> 3 -> 5 -> 9 -> NULL

--- Singly Linked List Operations ---
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
Enter value to search: 3
Value 3 found at position 3.

--- Singly Linked List Operations ---
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
Enter value to search: 11
Value 11 not found in the list.

--- Singly Linked List Operations ---
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