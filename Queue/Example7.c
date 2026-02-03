// =======================================================
// STACK USING SINGLE QUEUE (CIRCULAR QUEUE IMPLEMENTATION)
// Push Operation is COSTLY
// =======================================================
//
// NOTES:
// 1. Stack follows LIFO (Last In First Out)
// 2. Queue follows FIFO (First In First Out)
// 3. A circular queue is used to avoid false overflow
// 4. Push is made costly by rotating the queue
//
// Time Complexity:
// Push : O(n)
// Pop  : O(1)
// =======================================================

#include <stdio.h>
#define MAX 5

int q[MAX];
int front = -1, rear = -1;
int count = 0;

/*
ALGORITHM: ENQUEUE (CIRCULAR QUEUE)

Step 1: If count == MAX
        → Queue Overflow, stop.
Step 2: If queue is empty (front == -1)
        → set front = rear = 0.
Step 3: Else move rear circularly:
        rear = (rear + 1) % MAX.
Step 4: Insert element at q[rear].
Step 5: Increment count.
*/
void enqueue(int x) {
    if (count == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    q[rear] = x;
    count++;
}

/*
ALGORITHM: DEQUEUE (CIRCULAR QUEUE)

Step 1: If count == 0
        → Queue Underflow, stop.
Step 2: Store element at front.
Step 3: If front == rear
        → reset front = rear = -1.
Step 4: Else move front circularly:
        front = (front + 1) % MAX.
Step 5: Decrement count.
Step 6: Return deleted element.
*/
int dequeue() {
    int value;

    if (count == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    value = q[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    count--;
    return value;
}

/*
ALGORITHM: PUSH (STACK USING SINGLE QUEUE)

Step 1: If count == MAX
        → Stack Overflow, stop.
Step 2: Insert element into queue using enqueue().
Step 3: Store current queue size before insertion.
Step 4: Rotate the queue:
        Repeat size times:
        - Dequeue element
        - Enqueue the dequeued element
Step 5: Newly inserted element comes to front
        and behaves as stack top.
*/
void push(int x) {
    int size = count;

    if (count == MAX) {
        printf("Stack Overflow\n");
        return;
    }

    enqueue(x);

    for (int i = 0; i < size; i++)
        enqueue(dequeue());

    printf("Pushed: %d\n", x);
}

/*
ALGORITHM: POP (STACK USING SINGLE QUEUE)

Step 1: Delete element from queue using dequeue().
Step 2: The deleted element is the stack top.
*/
void pop() {
    int value = dequeue();

    if (value != -1)
        printf("Popped: %d\n", value);
}

/*
ALGORITHM: DISPLAY STACK

Step 1: If stack is empty (count == 0)
        → display "Stack is Empty".
Step 2: Start from front and print elements
        count times in circular manner.
Step 3: Elements printed from Top to Bottom.
*/
void display() {
    if (count == 0) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements (Top to Bottom): ");
    int i = front;
    for (int c = 0; c < count; c++) {
        printf("%d ", q[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// MAIN FUNCTION
int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

/*
Output:
1.Push  2.Pop  3.Display  4.Exit
Enter choice: 1
Enter value: 1
Pushed: 1

1.Push  2.Pop  3.Display  4.Exit
Enter choice: 1
Enter value: 2
Pushed: 2

1.Push  2.Pop  3.Display  4.Exit
Enter choice: 1
Enter value: 3
Pushed: 3

1.Push  2.Pop  3.Display  4.Exit
Enter choice: 3
Stack elements (Top to Bottom): 3 2 1 

1.Push  2.Pop  3.Display  4.Exit
Enter choice: 2
Popped: 3

1.Push  2.Pop  3.Display  4.Exit
Enter choice: 3
Stack elements (Top to Bottom): 2 1 

1.Push  2.Pop  3.Display  4.Exit
Enter choice: 4
*/