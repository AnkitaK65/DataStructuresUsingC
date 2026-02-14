/*
Topic: Skip List
Short Notes:
- A Skip List is an advanced linked list that allows fast search, insertion, and deletion.
- It uses multiple levels of linked lists.
- Level 0 is a normal sorted linked list.
- Higher levels act as "express lanes" to skip nodes.
- Average time complexity: O(log n)

Algorithm (Insertion):
1. Start from highest level and move forward while next value < key.
2. Store previous nodes at each level.
3. Generate random level for new node.
4. Insert node by adjusting forward pointers.

Algorithm (Search):
1. Start from highest level.
2. Move forward while next value < key.
3. Drop down levels until found or list ends.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 4
#define P 0.5   // probability factor

// Skip List Node
struct SkipNode {
    int data;
    struct SkipNode* forward[MAX_LEVEL + 1];
};

// Create new node
struct SkipNode* createNode(int level, int value) {
    struct SkipNode* node = (struct SkipNode*)malloc(sizeof(struct SkipNode));
    node->data = value;
    for (int i = 0; i <= MAX_LEVEL; i++)
        node->forward[i] = NULL;
    return node;
}

// Generate random level
int randomLevel() {
    int level = 0;
    while ((float)rand() / RAND_MAX < P && level < MAX_LEVEL)
        level++;
    return level;
}

// Create skip list
struct SkipNode* createSkipList() {
    return createNode(MAX_LEVEL, -1);  // header node
}

// Insert into skip list
void insert(struct SkipNode* header, int value) {
    struct SkipNode* update[MAX_LEVEL + 1];
    struct SkipNode* temp = header;

    for (int i = MAX_LEVEL; i >= 0; i--) {
        while (temp->forward[i] && temp->forward[i]->data < value)
            temp = temp->forward[i];
        update[i] = temp;
    }

    temp = temp->forward[0];

    if (temp == NULL || temp->data != value) {
        int level = randomLevel();
        struct SkipNode* newNode = createNode(level, value);

        for (int i = 0; i <= level; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        printf("Inserted %d\n", value);
    }
}

// Search in skip list
void search(struct SkipNode* header, int value) {
    struct SkipNode* temp = header;

    for (int i = MAX_LEVEL; i >= 0; i--) {
        while (temp->forward[i] && temp->forward[i]->data < value)
            temp = temp->forward[i];
    }

    temp = temp->forward[0];

    if (temp && temp->data == value)
        printf("%d found in Skip List\n", value);
    else
        printf("%d not found\n", value);
}

// Display skip list
void display(struct SkipNode* header) {
    printf("\n--- Skip List ---\n");
    for (int i = 0; i <= MAX_LEVEL; i++) {
        struct SkipNode* temp = header->forward[i];
        printf("Level %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->forward[i];
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    struct SkipNode* header = createSkipList();
    int choice, value;

    srand(time(NULL));

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(header, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(header, value);
                break;

            case 3:
                display(header);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}

/*
Output:
1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 10
Inserted 10

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 20
Inserted 20

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 30
Inserted 30

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 
1
Inserted 1

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 8
Invalid choice.

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 12
Inserted 12

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 3

--- Skip List ---
Level 0: 1 -> 10 -> 12 -> 20 -> 30 -> NULL
Level 1: 10 -> 20 -> NULL
Level 2: 10 -> 20 -> NULL
Level 3: 10 -> NULL
Level 4: 10 -> NULL

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 40
Inserted 40

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 100
Inserted 100

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 1000
Inserted 1000

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 3

--- Skip List ---
Level 0: 1 -> 10 -> 12 -> 20 -> 30 -> 40 -> 100 -> 1000 -> NULL
Level 1: 10 -> 20 -> NULL
Level 2: 10 -> 20 -> NULL
Level 3: 10 -> NULL
Level 4: 10 -> NULL

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 2
Enter value to search: 345
345 not found

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 2
Enter value to search: 1000
1000 found in Skip List

1. Insert
2. Search
3. Display
4. Exit
Enter choice: 4
*/