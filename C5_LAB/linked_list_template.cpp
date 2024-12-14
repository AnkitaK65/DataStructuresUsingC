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
class Node {
public:
    T data;
    Node* next;

    // Constructor
    Node(T value) : data(value), next(nullptr) {}
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
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Insert a new element at the end
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Delete a node with a given value
    void remove(T value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T>* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        if (!current->next) {
            cout << "Element not found in the list.\n";
            return;
        }
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Search for a node with a given value
    bool search(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Concatenate another linked list
    void concatenate(const LinkedList<T>& other) {
        if (!head) {
            head = other.head;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = other.head;
    }

    // Overload the + operator to concatenate two linked lists
    LinkedList<T> operator+(const LinkedList<T>& other) {
        LinkedList<T> result;
        Node<T>* current = head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }
        current = other.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }
        return result;
    }

    // Display the linked list
    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList<int> list1, list2;

    // Insert elements into the first list
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);

    cout << "List 1: ";
    list1.display();

    // Insert elements into the second list
    list2.insert(40);
    list2.insert(50);

    cout << "List 2: ";
    list2.display();

    // Concatenate two lists using a function
    list1.concatenate(list2);
    cout << "After concatenation (using function), List 1: ";
    list1.display();

    // Concatenate two lists using operator +
    LinkedList<int> list3 = list1 + list2;
    cout << "After concatenation (using operator +), List 3: ";
    list3.display();

    // Reverse the list
    list3.reverse();
    cout << "Reversed List 3: ";
    list3.display();

    // Search for an element
    int searchValue = 20;
    if (list3.search(searchValue)) {
        cout << "Element " << searchValue << " found in the list.\n";
    } else {
        cout << "Element " << searchValue << " not found in the list.\n";
    }

    // Delete an element
    list3.remove(20);
    cout << "After deleting 20, List 3: ";
    list3.display();

    return 0;
}
