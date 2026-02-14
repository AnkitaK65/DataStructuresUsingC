/* ============================================================
    Topic: Self-Organizing List (Move-To-Front Heuristic)

    Concept:
    - After searching an element,
        move it to the front of the list.

    Operations:
    1. Insert at End
    2. Search (Move-To-Front)
    3. Display

   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* ================= NODE STRUCTURE ================= */
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/* ================= INSERT AT END ================= */
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted %d.\n", value);
}

/* ================= SEARCH + MOVE TO FRONT ================= */
void searchMTF(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    printf("Element %d found.\n", key);

    /* If already at front, no need to move */
    if (prev == NULL) {
        printf("Element already at front.\n");
        return;
    }

    /* Remove node from current position */
    prev->next = temp->next;

    /* Move node to front */
    temp->next = head;
    head = temp;

    printf("Element moved to front.\n");
}

/* ================= DISPLAY ================= */
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("\nCurrent List:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* ================= MAIN ================= */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Self-Organizing List (MTF) ---\n");
        printf("1.Insert\n2.Search (Move-To-Front)\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchMTF(value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

/*
Output:

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 3
List is empty.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 1
Enter value: 10
Inserted 10.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 1
Enter value: 20
Inserted 20.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 1
Enter value: 30
Inserted 30.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 1
Enter value: 40
Inserted 40.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 1
Enter value: 50
Inserted 50.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 3

Current List:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 2
Enter value to search: 20
Element 20 found.
Element moved to front.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 3

Current List:
20 -> 10 -> 30 -> 40 -> 50 -> NULL

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 2
Enter value to search: 40
Element 40 found.
Element moved to front.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 3

Current List:
40 -> 20 -> 10 -> 30 -> 50 -> NULL

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 2
Enter value to search: 20
Element 20 found.
Element moved to front.

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 3

Current List:
20 -> 40 -> 10 -> 30 -> 50 -> NULL

--- Self-Organizing List (MTF) ---
1.Insert
2.Search (Move-To-Front)
3.Display
4.Exit
Enter choice: 4
*/