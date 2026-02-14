/*
===========================================================
Topic: Circular Singly Linked List (Dynamic Implementation)
===========================================================
Notes:
- Last node points back to head
- No NULL pointer in list
- Uses malloc() and free()

Operations:
1. Insert (Begin, End, Position)
2. Delete (Begin, End, By Value)
3. Search
4. Display
===========================================================
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at Beginning */
void insertAtBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

/* Insert at End */
void insertAtEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at end.\n", value);
}

/* Insert at Position (1-based) */
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, pos);
}

/* Delete from Beginning */
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        struct Node *last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Deleted from beginning.\n");
}

/* Delete from End */
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head, *prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Deleted from end.\n");
}

/* Delete by Value */
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    do {
        if (temp->data == value) {
            if (temp == head)
                deleteFromBeginning();
            else {
                prev->next = temp->next;
                free(temp);
            }
            printf("Deleted value %d.\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Value not found.\n");
}

/* Search */
void search(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Found %d at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Value not found.\n");
}

/* Display */
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

/* Main Menu */
int main() {
    int ch, val, pos;
    while (1) {
        printf("\n1.Insert Beg  2.Insert End  3.Insert Pos");
        printf("\n4.Delete Beg  5.Delete End  6.Delete By Value");
        printf("\n7.Search  8.Display  9.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val);
                    insertAtBeginning(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val);
                    insertAtEnd(val); break;
            case 3: printf("Enter value & position: ");
                    scanf("%d%d", &val, &pos);
                    insertAtPosition(val, pos); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: printf("Enter value: "); scanf("%d", &val);
                    deleteByValue(val); break;
            case 7: printf("Enter value: "); scanf("%d", &val);
                    search(val); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}

/*
Output:
1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 1
Enter value: 10
Inserted 10 at beginning.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 1
Enter value: 5
Inserted 5 at beginning.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 2
Enter value: 15
Inserted 15 at end.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 2
Enter value: 20
Inserted 20 at end.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 8
Circular List: 5 -> 10 -> 15 -> 20 -> (back to head)

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 2
Enter value: 25
Inserted 25 at end.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 2
Enter value: 30
Inserted 30 at end.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 8
Circular List: 5 -> 10 -> 15 -> 20 -> 25 -> 30 -> (back to head)

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 3
Enter value & position: 18 4
Inserted 18 at position 4.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 8
Circular List: 5 -> 10 -> 15 -> 18 -> 20 -> 25 -> 30 -> (back to head)

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 4
Deleted from beginning.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 8
Circular List: 10 -> 15 -> 18 -> 20 -> 25 -> 30 -> (back to head)

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 5
Deleted from end.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 8
Circular List: 10 -> 15 -> 18 -> 20 -> 25 -> (back to head)

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 6
Enter value: 18
Deleted value 18.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 8
Circular List: 10 -> 15 -> 20 -> 25 -> (back to head)

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 7
Enter value: 18
Value not found.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 7
Enter value: 15
Found 15 at position 2.

1.Insert Beg  2.Insert End  3.Insert Pos
4.Delete Beg  5.Delete End  6.Delete By Value
7.Search  8.Display  9.Exit
Choice: 9
*/