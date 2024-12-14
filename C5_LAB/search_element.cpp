/*
    Question 1:  
    Write a program to search an element from a list. Give the user the option to perform Linear or
    Binary search. Use Template functions.
*/

/*
    Brief Note:
    - A vector is a dynamic array provided by the STL that allows storing and managing elements efficiently.
    - C++ Templates are processed at compile time, and the compiler generates separate code for each type used.
    - Array is not used as Arrays are fixed in size and do not support dynamic resizing or STL functions, like sort(), ...

    Key Features of Vectors:
    - Dynamic resizing: Automatically adjusts its size when elements are added or removed.
    - Random access: Elements can be accessed using an index, just like arrays.
    - Efficient insertion and deletion: Can efficiently add/remove elements at the end using push_back() and pop_back().
    
    What is the STL?
    -The Standard Template Library (STL) is a collection of template classes and functions in C++ designed to make common programming tasks easier.
    - It includes:
        Containers: Classes like vector, list, and map to store collections of data.
        Iterators: Objects that allow traversal of container elements.
        Algorithms: Functions for searching, sorting, and other operations.

    STL Functions Used in This Code
    1. sort()
    Definition: sort(start, end)
    Purpose: Sorts elements in a range in ascending order.
    
    2. vector::begin()
    Definition: Returns an iterator to the first element of the vector.
    Purpose: Used as the starting point for operations like sorting.
    
    3. vector::end()
    Definition: Returns an iterator to the element following the last element of the vector.
    Purpose: Used as the endpoint for operations like sorting.
    
    4. vector::size()
    Definition: Returns the number of elements in the vector.
    Purpose: Used in the linearSearch function to determine the size of the array.
    
    5. vector::operator[]
    Definition: Allows accessing or modifying an element using the index.
    Purpose: Used to access elements in the vector directly, just like in arrays.

*/

#include <iostream>
#include <vector> // For vector container
#include <algorithm> // For sort function
using namespace std;

// Template function for Linear Search
template <typename T>
int linearSearch(const vector<T>& arr, T key) {
    // Uses vector::size() to determine the number of elements in the vector.
    for (int i = 0; i < arr.size(); i++) { // vector::operator[] is used for indexing
        if (arr[i] == key) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Template function for Binary Search
template <typename T>
int binarySearch(vector<T>& arr, T key) {
    // Uses STL sort() to sort the vector before performing binary search
    sort(arr.begin(), arr.end()); // sort(arr.begin(), arr.end()) sorts the entire vector
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) { // vector::operator[] is used here to access elements
            return mid; // Return the index if found
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    vector<int> arr(n); // Creates a dynamic array of size n using vector
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // vector::operator[] used to input elements
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    cout << "Choose the search method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (Note: List will be sorted)\n";
    int choice;
    cin >> choice;

    int index = -1; // Variable to store the result index

    switch (choice) {
        case 1:
            index = linearSearch(arr, key); // Calls the linearSearch template function
            break;
        case 2:
            index = binarySearch(arr, key); // Calls the binarySearch template function
            break;
        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    if (index != -1) {
        cout << "Element found at index " << index << " (0-based index).\n";
    } else {
        cout << "Element not found in the list.\n";
    }

    return 0;
}

//Output1:
//Enter the number of elements in the list: 5
// Enter 5 elements:
// 12
// 54
// 67
// 65
// 12
// Enter the element to search: 65
// Choose the search method:
// 1. Linear Search
// 2. Binary Search (Note: List will be sorted)
// 2
// Element not found in the list.

//Output2:
// Enter the number of elements in the list: 5
// Enter 5 elements:
// 1
// 2
// 3
// 4
// 5
// Enter the element to search: 4
// Choose the search method:
// 1. Linear Search
// 2. Binary Search (Note: List will be sorted)
// 1
// Element found at index 3 (0-based index).

//Output3:
// Enter the number of elements in the list: 5
// Enter 5 elements:
// 8
// 6
// 4
// 7
// 8
// Enter the element to search: 7
// Choose the search method:
// 1. Linear Search
// 2. Binary Search (Note: List will be sorted)
// 2
// Element found at index 2 (0-based index).