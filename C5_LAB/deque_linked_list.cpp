/*
Question 9: Create and perform different operations on Double-ended Queues (Deque) 
using Linked List implementation.
*/

#include <iostream>
using namespace std;

// Node structure for Deque
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// Deque class using Linked List
template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    // Constructor
    Deque() : front(nullptr), rear(nullptr) {}

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert at the front
    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted " << value << " at the front.\n";
    }

    // Insert at the rear
    void insertRear(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Inserted " << value << " at the rear.\n";
    }

    // Delete from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }
        Node<T>* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        cout << "Deleted element from the front.\n";
    }

    // Delete from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }
        Node<T>* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        cout << "Deleted element from the rear.\n";
    }

    // Peek the front element
    void peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty. No front element.\n";
            return;
        }
        cout << "Front element: " << front->data << "\n";
    }

    // Peek the rear element
    void peekRear() {
        if (isEmpty()) {
            cout << "Deque is empty. No rear element.\n";
            return;
        }
        cout << "Rear element: " << rear->data << "\n";
    }

    // Display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        Node<T>* temp = front;
        cout << "Deque elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to demonstrate operations
int main() {
    Deque<int> deque;
    int choice, value;

    do {
        cout << "\nDouble-ended Queue Operations using Linked List:\n";
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n";
        cout << "5. Peek Front\n6. Peek Rear\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the front: ";
                cin >> value;
                deque.insertFront(value);
                break;
            case 2:
                cout << "Enter the value to insert at the rear: ";
                cin >> value;
                deque.insertRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.peekFront();
                break;
            case 6:
                deque.peekRear();
                break;
            case 7:
                deque.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

/*
Output:
Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 7
Deque is empty.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 1
Enter the value to insert at the front: 1
Inserted 1 at the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 1
Enter the value to insert at the front: 0
Inserted 0 at the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 2
Enter the value to insert at the rear: 2
Inserted 2 at the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 2
Enter the value to insert at the rear: 3
Inserted 3 at the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 2
Enter the value to insert at the rear: 4
Inserted 4 at the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 2
Enter the value to insert at the rear: 5
Inserted 5 at the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 7
Deque elements: 0 1 2 3 4 5

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 5
Front element: 0

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 6
Rear element: 5

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deleted element from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 4
Deleted element from the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 7
Deque elements: 1 2 3 4

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 5
Front element: 1

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 6
Rear element: 4

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 2
Enter the value to insert at the rear: 66
Inserted 66 at the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 7
Deque elements: 1 2 3 4 66

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deleted element from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deleted element from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deleted element from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deleted element from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deleted element from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 7
Deque is empty.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 3
Deque is empty. Cannot delete from the front.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 4
Deque is empty. Cannot delete from the rear.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 5
Deque is empty. No front element.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 6
Deque is empty. No rear element.

Double-ended Queue Operations using Linked List:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Peek Front
6. Peek Rear
7. Display
8. Exit
Enter your choice: 8
Exiting program.
*/