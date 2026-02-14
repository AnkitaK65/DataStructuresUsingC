/* ============================================================
    Topic: Doubly Circular Linked List (Pointer Implementation)

    Properties:
    - Each node has prev and next
    - last->next = head
    - head->prev = last
    - No NULL in circular list

    Operations:
    Insert Begin / End
    Delete Begin / End
    Display Forward / Backward
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* ================= INSERT AT BEGINNING ================= */
void insertBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

/* ================= INSERT AT END ================= */
void insertEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }
    printf("Inserted %d at end.\n", value);
}

/* ================= DELETE FROM BEGINNING ================= */
void deleteBeginning() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        struct Node *temp = head;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
    }
    printf("Deleted from beginning.\n");
}

/* ================= DELETE FROM END ================= */
void deleteEnd() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        struct Node *secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        free(last);
    }
    printf("Deleted from end.\n");
}

/* ================= DISPLAY FORWARD ================= */
void displayForward() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nForward Traversal:\n");

    do {
        printf("[%d] <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

/* ================= DISPLAY BACKWARD ================= */
void displayBackward() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head->prev;
    printf("\nBackward Traversal:\n");

    do {
        printf("[%d] <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);

    printf("(back to last)\n");
}

/* ================= MAIN ================= */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Doubly Circular Linked List (Pointer) ---\n");
        printf("1.Insert Beginning\n2.Insert End\n");
        printf("3.Delete Beginning\n4.Delete End\n");
        printf("5.Display Forward\n6.Display Backward\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    insertBeginning(value); break;
            case 2: printf("Enter value: ");
                    scanf("%d", &value);
                    insertEnd(value); break;
            case 3: deleteBeginning(); break;
            case 4: deleteEnd(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
            case 7: return 0;
        }
    }
}

/*
OUtput:
--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 5
List empty.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 1
Enter value: 5
Inserted 5 at beginning.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 2
Enter value: 10
Inserted 10 at end.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 1
Enter value: 2
Inserted 2 at beginning.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 2
Enter value: 20
Inserted 20 at end.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 2
Enter value: 30
Inserted 30 at end.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 2
Enter value: 40
Inserted 40 at end.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 5

Forward Traversal:
[2] <-> [5] <-> [10] <-> [20] <-> [30] <-> [40] <-> (back to head)

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 3
Deleted from beginning.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 5

Forward Traversal:
[5] <-> [10] <-> [20] <-> [30] <-> [40] <-> (back to head)

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 4
Deleted from end.

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 5

Forward Traversal:
[5] <-> [10] <-> [20] <-> [30] <-> (back to head)

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 6

Backward Traversal:
[30] <-> [20] <-> [10] <-> [5] <-> (back to last)

--- Doubly Circular Linked List (Pointer) ---
1.Insert Beginning
2.Insert End
3.Delete Beginning
4.Delete End
5.Display Forward
6.Display Backward
7.Exit
Enter choice: 7
*/