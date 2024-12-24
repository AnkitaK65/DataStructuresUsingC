/*
 * Question 7: Perform Stack operations using Array implementation with Templates
 */

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;            // Array to hold stack elements
    int top;           // Index of the top element
    int capacity;      // Maximum capacity of the stack

public:
    // Constructor to initialize the stack with a given capacity
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];  // Allocate memory for the stack
        top = -1;               // Stack is initially empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;  // Free the memory allocated for the array
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Function to push an element onto the stack
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow: Cannot push " << value << ". Stack is full.\n";
            return;
        }
        arr[++top] = value;  // Increment top and add the value to the stack
        cout << "Pushed " << value << " onto the stack\n";
    }

    // Function to pop an element from the stack
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop from an empty stack.\n";
            return T();  // Return default value of T if the stack is empty
        }
        T poppedValue = arr[top--];  // Return the top element and decrement top
        cout << "Popped " << poppedValue << " from the stack\n";
        return poppedValue;
    }

    // Function to peek at the top element of the stack
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek.\n";
            return T();  // Return default value of T if the stack is empty
        }
        return arr[top];  // Return the top element without removing it
    }

    // Function to display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice, value, size;

    cout << "Enter the size of the stack: ";
    cin >> size;

    // Create a stack of the user-specified size for integer elements
    Stack<int> stack(size);

    do {
        cout << "\nStack Operations using Array (Template):\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer to avoid extra characters being read
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element is " << stack.peek() << endl;
                break;
            case 4:
                stack.display();
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
Enter the size of the stack: 5

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 1
Pushed 1 onto the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 2
Pushed 2 onto the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 3
Pushed 3 onto the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 4
Pushed 4 onto the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 5
Pushed 5 onto the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 6
Stack Overflow: Cannot push 6. Stack is full.

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 6
Invalid choice, please try again.

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 1 2 3 4 5

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 5 from the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 1 2 3 4

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
Top element is 4

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 1 2 3 4

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter the value to push: 7
Pushed 7 onto the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 1 2 3 4 7

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 3
Top element is 7

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 7 from the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack elements: 1 2 3 4

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 4 from the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 3 from the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 2 from the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Popped 1 from the stack

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 2
Stack Underflow: Cannot pop from an empty stack.

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 4
Stack is empty.

Stack Operations using Array (Template):
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice: 5
Exiting...
*/