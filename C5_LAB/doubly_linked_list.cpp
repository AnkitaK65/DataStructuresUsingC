/*
    Question 4: 
    Implement Doubly Linked List using templates. 
    Include functions for insertion, deletion and search of a number, and reverse the list.
*/

#include <iostream>
using namespace std;

// Node definition for Doubly Linked List
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    // Constructor with initializer list
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Insert at the beginning
    void insertAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node by value
    void deleteByValue(T value) {
        if (!head) {
            cout << "List is empty. Deletion not possible.\n";
            return;
        }
        Node<T>* temp = head;

        // Find the node to delete
        while (temp && temp->data != value) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value not found in the list.\n";
            return;
        }

        // If it's the head node
        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }

        // If it's a middle or last node
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    // Search for a value in the list
    bool search(T value) {
        Node<T>* current = head; // Start from the head
        while (current != nullptr) { // Traverse until the end of the list
            if (current->data == value) {
                return true; // Value found
            }
            current = current->next; // Move to the next node
        }
        return false; // Value not found
    }

    // Reverse the doubly linked list
    void reverse() {
        if (!head || !head->next) return; // If list is empty or has only one node
        Node<T>* temp = nullptr;
        Node<T>* current = head;

        // Swap next and prev for all nodes
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Update head to the last node
        if (temp) head = temp->prev;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    DoublyLinkedList<int> dll;

    // Menu-driven program
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete by Value\n";
        cout << "4. Search\n";
        cout << "5. Reverse the List\n";
        cout << "6. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                dll.deleteByValue(value);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (dll.search(value)) {
                    cout << "Value found in the list.\n";
                } else {
                    cout << "Value not found in the list.\n";
                }
                break;
            case 5:
                dll.reverse();
                cout << "List reversed.\n";
                break;
            case 6:
                dll.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

/*
Output:

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 1
    Enter value to insert at the beginning: 1

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 6
    1 <-> NULL

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 1
    Enter value to insert at the beginning: 0

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 2
    Enter value to insert at the end: 2

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 2
    Enter value to insert at the end: 3

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 2
    Enter value to insert at the end: 4

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 6
    0 <-> 1 <-> 2 <-> 3 <-> 4 <-> NULL

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 4
    Enter value to search: 4
    Value found in the list.

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 5
    List reversed.

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 6
    4 <-> 3 <-> 2 <-> 1 <-> 0 <-> NULL

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 3
    Enter value to delete: 0

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 6
    4 <-> 3 <-> 2 <-> 1 <-> NULL

    Menu:
    1. Insert at Beginning
    2. Insert at End
    3. Delete by Value
    4. Search
    5. Reverse the List
    6. Display List
    0. Exit
    Enter your choice: 0
    Exiting...
*/
