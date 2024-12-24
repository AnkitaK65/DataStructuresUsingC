/*
    Question 5:
    Implement Circular Linked List using templates. Include functions for insertion, deletion and 
    search of a number, reverse the list.
*/

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    // Constructor to initialize a new node
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head) return;
        Node<T>* temp = head->next;
        while (temp != head) {
            Node<T>* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        delete head;
    }

    // Insert at the end of the list
    void insertEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at the beginning of the list
    void insertBegin(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode; // Update head
    }

    // Delete a node by value
    void deleteByValue(T value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        // If the node to delete is the head node
        if (head->data == value) {
            if (head->next == head) { // Only one node in the list
                delete head;
                head = nullptr;
                return;
            }
            // Find the last node to update its next pointer
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node<T>* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        // Traverse the list to find the node
        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
                return;
            }
        } while (temp != head);

        cout << "Value not found in the list.\n";
    }

    // Search for a value in the list
    bool search(T value) {
        if (!head) return false;
        Node<T>* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Reverse the circular linked list
    void reverse() {
        // If the list is empty or has only one node, no reversal is needed.
        if (!head || head->next == head)
            return;

        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next;

        // Reverse the linked list as if it's a singly linked list
        do {
            next = current->next;  // Store the next node
            current->next = prev;  // Reverse the current node's link
            prev = current;        // Move prev to the current node
            current = next;        // Move current to the next node
        } while (current != head);

        // Adjust the circular links
        head->next = prev;  // The old head (now the tail) points to the new head
        head = prev;        // Update the head to the new head
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node<T>* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head) ["<<head->data<<"]\n";
    }
};

int main() {
    CircularLinkedList<int> list;
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
                list.insertBegin(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteByValue(value);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Value found in the list.\n";
                } else {
                    cout << "Value not found in the list.\n";
                }
                break;
            case 5:
                list.reverse();
                cout << "List reversed.\n";
                break;
            case 6:
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
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
Enter your choice: 2
Enter value to insert at the end: 7

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete by Value
4. Search
5. Reverse the List
6. Display List
0. Exit
Enter your choice: 2
Enter value to insert at the end: 5

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete by Value
4. Search
5. Reverse the List
6. Display List
0. Exit
Enter your choice: 6
0 -> 1 -> 2 -> 3 -> 4 -> 7 -> 5 -> (head)

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete by Value
4. Search
5. Reverse the List
6. Display List
0. Exit
Enter your choice: 3
Enter value to delete: 7

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete by Value
4. Search
5. Reverse the List
6. Display List
0. Exit
Enter your choice: 6
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> (head)

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete by Value
4. Search
5. Reverse the List
6. Display List
0. Exit
Enter your choice: 2
Enter value to insert at the end: 6

Menu:
1. Insert at Beginning
2. Insert at End
3. Delete by Value
4. Search
5. Reverse the List
6. Display List
0. Exit
Enter your choice: 6
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> (head)

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
6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> (head)

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