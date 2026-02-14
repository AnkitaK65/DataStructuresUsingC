/* ============================================================
    Topic: Doubly Circular Linked List using Arrays

    Description:
    - Simulates doubly circular linked list using arrays
    - data[]  -> stores values
    - next[]  -> stores next index
    - prev[]  -> stores previous index
    - head    -> index of first node
    - freeIndex -> next free location in array

    Circular Conditions:
    next[last] = head
    prev[head] = last

   ============================================================ */

#include <stdio.h>
#define MAX 20
#define NULL_INDEX -1

int data[MAX], next[MAX], prev[MAX];
int head = NULL_INDEX;
int freeIndex = 0;

/* ================= INSERT AT BEGINNING ================= */
void insertBeginning(int value) {
    if (freeIndex >= MAX) {
        printf("Overflow! No space left.\n");
        return;
    }

    int newNode = freeIndex++;
    data[newNode] = value;

    if (head == NULL_INDEX) {
        next[newNode] = newNode;
        prev[newNode] = newNode;
        head = newNode;
    } else {
        int last = prev[head];

        next[newNode] = head;
        prev[newNode] = last;

        next[last] = newNode;
        prev[head] = newNode;

        head = newNode;
    }

    printf("Inserted %d at beginning.\n", value);
}

/* ================= INSERT AT END ================= */
void insertEnd(int value) {
    if (freeIndex >= MAX) {
        printf("Overflow! No space left.\n");
        return;
    }

    int newNode = freeIndex++;
    data[newNode] = value;

    if (head == NULL_INDEX) {
        next[newNode] = newNode;
        prev[newNode] = newNode;
        head = newNode;
    } else {
        int last = prev[head];

        next[last] = newNode;
        prev[newNode] = last;

        next[newNode] = head;
        prev[head] = newNode;
    }

    printf("Inserted %d at end.\n", value);
}

/* ================= INSERT AT POSITION ================= */
void insertAtPosition(int value, int pos) {
    if (pos <= 1 || head == NULL_INDEX) {
        insertBeginning(value);
        return;
    }

    int temp = head;
    int count = 1;

    while (count < pos - 1 && next[temp] != head) {
        temp = next[temp];
        count++;
    }

    if (next[temp] == head) {
        insertEnd(value);
        return;
    }

    if (freeIndex >= MAX) {
        printf("Overflow! No space left.\n");
        return;
    }

    int newNode = freeIndex++;
    data[newNode] = value;

    next[newNode] = next[temp];
    prev[newNode] = temp;

    prev[next[temp]] = newNode;
    next[temp] = newNode;

    printf("Inserted %d at position %d.\n", value, pos);
}

/* ================= DELETE FROM BEGINNING ================= */
void deleteBeginning() {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    if (next[head] == head) {
        head = NULL_INDEX;
    } else {
        int last = prev[head];
        head = next[head];

        prev[head] = last;
        next[last] = head;
    }

    printf("Deleted from beginning.\n");
}

/* ================= DELETE FROM END ================= */
void deleteEnd() {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int last = prev[head];

    if (last == head) {
        head = NULL_INDEX;
    } else {
        int secondLast = prev[last];

        next[secondLast] = head;
        prev[head] = secondLast;
    }

    printf("Deleted from end.\n");
}

/* ================= DELETE AT POSITION ================= */
void deleteAtPosition(int pos) {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    if (pos <= 1) {
        deleteBeginning();
        return;
    }

    int temp = head;
    int count = 1;

    while (count < pos && next[temp] != head) {
        temp = next[temp];
        count++;
    }

    if (count != pos) {
        printf("Invalid position.\n");
        return;
    }

    if (temp == prev[head]) {
        deleteEnd();
        return;
    }

    int before = prev[temp];
    int after = next[temp];

    next[before] = after;
    prev[after] = before;

    printf("Deleted node at position %d.\n", pos);
}

/* ================= DELETE BY VALUE ================= */
void deleteByValue(int value) {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int temp = head;

    do {
        if (data[temp] == value) {
            if (temp == head) {
                deleteBeginning();
                return;
            }

            if (temp == prev[head]) {
                deleteEnd();
                return;
            }

            int before = prev[temp];
            int after = next[temp];

            next[before] = after;
            prev[after] = before;

            printf("Deleted value %d.\n", value);
            return;
        }

        temp = next[temp];

    } while (temp != head);

    printf("Value not found.\n");
}

/* ================= SEARCH ================= */
void search(int value) {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int temp = head;
    int pos = 1;

    do {
        if (data[temp] == value) {
            printf("Value found at position %d (index %d).\n", pos, temp);
            return;
        }
        temp = next[temp];
        pos++;
    } while (temp != head);

    printf("Value not found.\n");
}

/* ================= DISPLAY ================= */
void display() {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int temp = head;

    printf("\n========= ARRAY REPRESENTATION =========\n");
    printf("Index\tData\tPrev\tNext\n");
    printf("----------------------------------------\n");

    do {
        printf("%d\t%d\t%d\t%d\n",
               temp, data[temp], prev[temp], next[temp]);
        temp = next[temp];
    } while (temp != head);

    printf("Head Index: %d\n", head);

    printf("\nForward Order: ");
    temp = head;
    do {
        printf("%d <-> ", data[temp]);
        temp = next[temp];
    } while (temp != head);
    printf("(back to head)\n");

    printf("Backward Order: ");
    temp = prev[head];
    do {
        printf("%d <-> ", data[temp]);
        temp = prev[temp];
    } while (temp != prev[head]);
    printf("(back to last)\n");
}

/* ================= MAIN ================= */
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Circular Linked List (Array) ---\n");
        printf("1.Insert Beginning\n2.Insert End\n3.Insert Position\n");
        printf("4.Delete Beginning\n5.Delete End\n6.Delete Position\n");
        printf("7.Delete by Value\n8.Search\n9.Display\n10.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value); break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value); break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &pos);
                insertAtPosition(value, pos); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos); break;
            case 7:
                printf("Enter value: ");
                scanf("%d", &value);
                deleteByValue(value); break;
            case 8:
                printf("Enter value: ");
                scanf("%d", &value);
                search(value); break;
            case 9: display(); break;
            case 10: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}

/*
Output:
--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 1
Enter value: 10
Inserted 10 at beginning.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 1
Enter value: 5
Inserted 5 at beginning.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 2
Enter value: 15
Inserted 15 at end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 2
Enter value: 20
Inserted 20 at end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 2
Enter value: 25
Inserted 25 at end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 2
Enter value: 30
Inserted 30 at end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 2
Enter value: 40
Inserted 40 at end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 9

========= ARRAY REPRESENTATION =========
Index   Data    Prev    Next
----------------------------------------
1       5       6       0
0       10      1       2
2       15      0       3
3       20      2       4
4       25      3       5
5       30      4       6
6       40      5       1
Head Index: 1

Forward Order: 5 <-> 10 <-> 15 <-> 20 <-> 25 <-> 30 <-> 40 <-> (back to head)
Backward Order: 40 <-> 30 <-> 25 <-> 20 <-> 15 <-> 10 <-> 5 <-> (back to last)

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 3
Enter value and position: 35 7
Inserted 35 at position 7.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 9

========= ARRAY REPRESENTATION =========
Index   Data    Prev    Next
----------------------------------------
1       5       6       0
0       10      1       2
2       15      0       3
3       20      2       4
4       25      3       5
5       30      4       7
7       35      5       6
6       40      7       1
Head Index: 1

Forward Order: 5 <-> 10 <-> 15 <-> 20 <-> 25 <-> 30 <-> 35 <-> 40 <-> (back to head)
Backward Order: 40 <-> 35 <-> 30 <-> 25 <-> 20 <-> 15 <-> 10 <-> 5 <-> (back to last)

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 4
Deleted from beginning.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 5
Deleted from end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 9

========= ARRAY REPRESENTATION =========
Index   Data    Prev    Next
----------------------------------------
0       10      7       2
2       15      0       3
3       20      2       4
4       25      3       5
5       30      4       7
7       35      5       0
Head Index: 0

Forward Order: 10 <-> 15 <-> 20 <-> 25 <-> 30 <-> 35 <-> (back to head)
Backward Order: 35 <-> 30 <-> 25 <-> 20 <-> 15 <-> 10 <-> (back to last)

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 6
Enter position: 2
Deleted node at position 2.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 9

========= ARRAY REPRESENTATION =========
Index   Data    Prev    Next
----------------------------------------
0       10      7       3
3       20      0       4
4       25      3       5
5       30      4       7
7       35      5       0
Head Index: 0

Forward Order: 10 <-> 20 <-> 25 <-> 30 <-> 35 <-> (back to head)
Backward Order: 35 <-> 30 <-> 25 <-> 20 <-> 10 <-> (back to last)

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 7
Enter value: 35
Deleted from end.

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 9

========= ARRAY REPRESENTATION =========
Index   Data    Prev    Next
----------------------------------------
0       10      5       3
3       20      0       4
4       25      3       5
5       30      4       0
Head Index: 0

Forward Order: 10 <-> 20 <-> 25 <-> 30 <-> (back to head)
Backward Order: 30 <-> 25 <-> 20 <-> 10 <-> (back to last)

--- Doubly Circular Linked List (Array) ---
1.Insert Beginning
2.Insert End
3.Insert Position
4.Delete Beginning
5.Delete End
6.Delete Position
7.Delete by Value
8.Search
9.Display
10.Exit
Enter choice: 10
*/