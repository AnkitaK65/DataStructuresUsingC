/*
    Question 3:
    Implement Linked List using templates. Include functions for:
    1. Insertion
    2. Deletion
    3. Search for a number
    4. Reverse the list
    5. Concatenate two linked lists (include a function and overload operator +)
*/

#include <iostream>
using namespace std;

// Node structure
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
    /*
        Constructor: Initializes a Node with a given value
        and sets the 'next' pointer to nullptr (indicating the end of the list initially)
        1. Initializer list directly initializes members, avoiding default initialization followed by reassignment.
        2. More efficient and preferred in modern C++ for cleaner, concise code.

        Node(T val) 
            : data(val), // Initializes 'data' with the value passed as 'val'
            next(nullptr) // Sets 'next' pointer to nullptr (no next node yet)
        {}
    */

   /* IT IS SAME AS -- 
        Constructor: Initializes the members in the constructor body
        1. Members are first default-initialized (for example, 'data' is uninitialized here).
        2. Reassignment occurs after default initialization, making it less efficient.
        
        Node(T val) {
            data = val;     // Assign the value 'val' to 'data'
            next = nullptr; // Initialize the 'next' pointer to nullptr
        }
   */
};

// Linked List class
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at the end of the list
    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete an element from the list
    void remove(T key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // If the element to be deleted is the head
        if (head->data == key) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Find the element to delete
        Node<T>* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }

        // If the element was not found
        if (!temp->next) {
            cout << "Element not found in the list.\n";
            return;
        }

        // Delete the node
        Node<T>* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search for an element in the list
    bool search(T key) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Reverse the list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        Node<T>* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // Concatenate another linked list (Deep Copy)
    void concatenate(const LinkedList<T>& other) {
        if (!other.head) return; // Nothing to concatenate if the other list is empty
        if (!head) {
            head = other.head;
            return;
        }

        Node<T>* current = other.head;
        while (current) {
            this->insert(current->data); // Insert a copy of each node
            current = current->next;
        }
    }

    // Overload the + operator for concatenation (Deep Copy)
    LinkedList<T> operator+(const LinkedList<T>& other) {
        LinkedList<T> result;

        // Copy elements from the current list
        Node<T>* current = head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }

        // Copy elements from the other list
        current = other.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }

        return result;
    }

    // Print the list
    void print() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;

    // Inserting elements into list 1
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);

    // Inserting elements into list 2
    list2.insert(40);
    list2.insert(50);

    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();

    // Concatenation using function
    list1.concatenate(list2);
    cout << "After concatenation (using function), List 1: ";
    list1.print();

    // Concatenation using overloaded + operator
    LinkedList<int> list3 = list1 + list2;
    cout << "After concatenation (using operator +), List 3: ";
    list3.print();

    // Reverse the concatenated list
    list3.reverse();
    cout << "Reversed List 3: ";
    list3.print();

    // Search for an element in List 3
    int key = 20;
    if (list3.search(key)) {
        cout << "Element " << key << " found in the list." << endl;
    } else {
        cout << "Element " << key << " not found in the list." << endl;
    }

    // Remove an element from List 3
    list3.remove(20);
    cout << "After deleting 20, List 3: ";
    list3.print();

    return 0;
}

//Output:
// List 1: 10 -> 20 -> 30 -> NULL
// List 2: 40 -> 50 -> NULL
// After concatenation (using function), List 1: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
// After concatenation (using operator +), List 3: 10 -> 20 -> 30 -> 40 -> 50 -> 40 -> 50 -> NULL
// Reversed List 3: 50 -> 40 -> 50 -> 40 -> 30 -> 20 -> 10 -> NULL
// Element 20 found in the list.
// After deleting 20, List 3: 50 -> 40 -> 50 -> 40 -> 30 -> 10 -> NULL