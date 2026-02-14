/*
===========================================================
Topic: Circular Singly Linked List using Arrays
===========================================================
Notes:
- Uses arrays instead of pointers
- next[] simulates link
- free list used for memory management
===========================================================
*/

#include <stdio.h>
#define MAX 10
#define NULL_INDEX -1

int data[MAX], next[MAX];
int head = NULL_INDEX, freeHead = 0;

/* Initialize free list */
void init() {
    for (int i = 0; i < MAX - 1; i++)
        next[i] = i + 1;
    next[MAX - 1] = NULL_INDEX;
}

/* Insert at Beginning */
void insertAtBeginning(int value) {
    if (freeHead == NULL_INDEX) {
        printf("Overflow.\n");
        return;
    }

    int newNode = freeHead;
    freeHead = next[freeHead];
    data[newNode] = value;

    if (head == NULL_INDEX) {
        head = newNode;
        next[newNode] = head;
    } else {
        int last = head;
        while (next[last] != head)
            last = next[last];

        next[newNode] = head;
        next[last] = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

/* Insert at End */
void insertAtEnd(int value) {
    if (freeHead == NULL_INDEX) {
        printf("Overflow.\n");
        return;
    }

    int newNode = freeHead;
    freeHead = next[freeHead];
    data[newNode] = value;

    if (head == NULL_INDEX) {
        head = newNode;
        next[newNode] = head;
    } else {
        int temp = head;
        while (next[temp] != head)
            temp = next[temp];

        next[temp] = newNode;
        next[newNode] = head;
    }
    printf("Inserted %d at end.\n", value);
}

/* Delete from Beginning */
void deleteFromBeginning() {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int temp = head;

    if (next[head] == head)
        head = NULL_INDEX;
    else {
        int last = head;
        while (next[last] != head)
            last = next[last];

        head = next[head];
        next[last] = head;
    }

    next[temp] = freeHead;
    freeHead = temp;
    printf("Deleted from beginning.\n");
}

/* Delete from End */
void deleteFromEnd() {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int temp = head, prev = NULL_INDEX;

    if (next[head] == head) {
        next[head] = freeHead;
        freeHead = head;
        head = NULL_INDEX;
    } else {
        while (next[temp] != head) {
            prev = temp;
            temp = next[temp];
        }
        next[prev] = head;
        next[temp] = freeHead;
        freeHead = temp;
    }
    printf("Deleted from end.\n");
}

/* ================= DISPLAY ================= */
void display() {
    if (head == NULL_INDEX) {
        printf("List empty.\n");
        return;
    }

    int temp = head;

    /* -------- 1️⃣ ARRAY REPRESENTATION -------- */
    printf("\n========= ARRAY REPRESENTATION =========\n");
    printf("Index\tData\tNext\n");
    printf("---------------------------------------\n");

    do {
        printf("%d\t%d\t%d\n", temp, data[temp], next[temp]);
        temp = next[temp];
    } while (temp != head);

    printf("Head Index: %d\n", head);


    /* -------- 2️⃣ CIRCULAR ORDER (DATA ONLY) -------- */
    printf("\n========= CIRCULAR ORDER =========\n");
    temp = head;
    do {
        printf("%d -> ", data[temp]);
        temp = next[temp];
    } while (temp != head);
    printf("(back to head)\n");


    /* -------- 3️⃣ LINKED LIST REPRESENTATION -------- */
    printf("\n========= LINKED LIST REPRESENTATION =========\n");
    temp = head;
    do {
        printf("[%d | next:%d] -> ", data[temp], next[temp]);
        temp = next[temp];
    } while (temp != head);
    printf("(points back to head index %d)\n", head);

    printf("=============================================\n");
}

int main() {
    init();
    int ch, val;
    while (1) {
        printf("\n1.Insert Beg 2.Insert End 3.Delete Beg");
        printf("\n4.Delete End 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val);
                    insertAtBeginning(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val);
                    insertAtEnd(val); break;
            case 3: deleteFromBeginning(); break;
            case 4: deleteFromEnd(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}

/*
Output:
1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5
List empty.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 1
Enter value: 10
Inserted 10 at beginning.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 1
Enter value: 5
Inserted 5 at beginning.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5

========= ARRAY REPRESENTATION =========
Index   Data    Next
---------------------------------------
1       5       0
0       10      1
Head Index: 1

========= CIRCULAR ORDER =========
5 -> 10 -> (back to head)

========= LINKED LIST REPRESENTATION =========
[5 | next:0] -> [10 | next:1] -> (points back to head index 1)
=============================================

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 15
Inserted 15 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 20
Inserted 20 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 30
Inserted 30 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5

========= ARRAY REPRESENTATION =========
Index   Data    Next
---------------------------------------
1       5       0
0       10      2
2       15      3
3       20      4
4       30      1
Head Index: 1

========= CIRCULAR ORDER =========
5 -> 10 -> 15 -> 20 -> 30 -> (back to head)

========= LINKED LIST REPRESENTATION =========
[5 | next:0] -> [10 | next:2] -> [15 | next:3] -> [20 | next:4] -> [30 | next:1] -> (points back to head index 1)
=============================================

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 3
Deleted from beginning.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5

========= ARRAY REPRESENTATION =========
Index   Data    Next
---------------------------------------
0       10      2
2       15      3
3       20      4
4       30      0
Head Index: 0

========= CIRCULAR ORDER =========
10 -> 15 -> 20 -> 30 -> (back to head)

========= LINKED LIST REPRESENTATION =========
[10 | next:2] -> [15 | next:3] -> [20 | next:4] -> [30 | next:0] -> (points back to head index 0)
=============================================

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 11
Inserted 11 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 12
Inserted 12 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 13
Inserted 13 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 14
Inserted 14 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 15
Inserted 15 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 16
Inserted 16 at end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 2
Enter value: 17
Overflow.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5

========= ARRAY REPRESENTATION =========
Index   Data    Next
---------------------------------------
0       10      2
2       15      3
3       20      4
4       30      1
1       11      5
5       12      6
6       13      7
7       14      8
8       15      9
9       16      0
Head Index: 0

========= CIRCULAR ORDER =========
10 -> 15 -> 20 -> 30 -> 11 -> 12 -> 13 -> 14 -> 15 -> 16 -> (back to head)

========= LINKED LIST REPRESENTATION =========
[10 | next:2] -> [15 | next:3] -> [20 | next:4] -> [30 | next:1] -> [11 | next:5] -> [12 | next:6] -> [13 | next:7] -> [14 | next:8] -> [15 | next:9] -> [16 | next:0] -> (points back to head index 0)
=============================================

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 4
Deleted from end.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5

========= ARRAY REPRESENTATION =========
Index   Data    Next
---------------------------------------
0       10      2
2       15      3
3       20      4
4       30      1
1       11      5
5       12      6
6       13      7
7       14      8
8       15      0
Head Index: 0

========= CIRCULAR ORDER =========
10 -> 15 -> 20 -> 30 -> 11 -> 12 -> 13 -> 14 -> 15 -> (back to head)

========= LINKED LIST REPRESENTATION =========
[10 | next:2] -> [15 | next:3] -> [20 | next:4] -> [30 | next:1] -> [11 | next:5] -> [12 | next:6] -> [13 | next:7] -> [14 | next:8] -> [15 | next:0] -> (points back to head index 0)
=============================================

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 3
Deleted from beginning.

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 5

========= ARRAY REPRESENTATION =========
Index   Data    Next
---------------------------------------
2       15      3
3       20      4
4       30      1
1       11      5
5       12      6
6       13      7
7       14      8
8       15      2
Head Index: 2

========= CIRCULAR ORDER =========
15 -> 20 -> 30 -> 11 -> 12 -> 13 -> 14 -> 15 -> (back to head)

========= LINKED LIST REPRESENTATION =========
[15 | next:3] -> [20 | next:4] -> [30 | next:1] -> [11 | next:5] -> [12 | next:6] -> [13 | next:7] -> [14 | next:8] -> [15 | next:2] -> (points back to head index 2)
=============================================

1.Insert Beg 2.Insert End 3.Delete Beg
4.Delete End 5.Display 6.Exit
Choice: 6
*/