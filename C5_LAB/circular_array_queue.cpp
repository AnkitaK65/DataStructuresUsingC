/*
 * Question 8: Perform Queues operations using Circular Array implementation. Use Templates. 
 */

#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    T* arr;        // Array to hold queue elements
    int front;     // Front points to the front element in the queue
    int rear;      // Rear points to the next available slot in the queue
    int capacity;  // Maximum capacity of the queue
    int size;      // Current size of the queue

public:
    // Constructor to initialize the queue with a given capacity
    CircularQueue(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];  // Allocate memory for the queue
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free the allocated memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot enqueue " << value << ". Queue is full.\n";
            return;
        }

        // If the queue is empty, set both front and rear to 0
        if (isEmpty()) {
            front = rear = 0;
        } else {
            // Update rear using circular increment
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;  // Add the element to the rear of the queue
        size++;
        cout << "Enqueued " << value << " to the queue.\n";
    }

    // Function to remove an element from the queue (dequeue)
    T dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Cannot dequeue from an empty queue.\n";
            return T();  // Return default value of T if the queue is empty
        }

        T dequeuedValue = arr[front];  // Get the front element
        if (front == rear) {
            // If there's only one element in the queue, reset the queue to empty
            front = rear = -1;
        } else {
            // Update front using circular increment
            front = (front + 1) % capacity;
        }

        size--;
        cout << "Dequeued " << dequeuedValue << " from the queue.\n";
        return dequeuedValue;
    }

    // Function to peek at the front element of the queue
    T peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek.\n";
            return T();  // Return default value of T if the queue is empty
        }
        return arr[front];  // Return the front element without removing it
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;  // Display the rear element
    }
};

int main() {
    int choice, value, size;

    cout << "Enter the size of the queue: ";
    cin >> size;

    // Create a queue of the user-specified size for integer elements
    CircularQueue<int> queue(size);

    do {
        cout << "\nQueue Operations using Circular Array (Template):\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer to avoid extra characters being read
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Front element is " << queue.peek() << endl;
                break;
            case 4:
                queue.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
/*
Output:
Enter the size of the queue: 5

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 109
Enqueued 109 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 29
Enqueued 29 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 23
Enqueued 23 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 109 29 23

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 3
Front element is 109

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 109 from the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 29 23

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 5
Enqueued 5 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 7
Enqueued 7 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 56
Enqueued 56 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 29 23 5 7 56

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 34
Queue Overflow: Cannot enqueue 34. Queue is full.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 3
Front element is 29

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 29 from the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 23 from the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 5 from the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 7 from the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 56

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 3
Front element is 56

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Dequeued 56 from the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 2
Queue Underflow: Cannot dequeue from an empty queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue is empty.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to enqueue: 12
Enqueued 12 to the queue.

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 4
Queue elements: 12

Queue Operations using Circular Array (Template):
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting...
*/