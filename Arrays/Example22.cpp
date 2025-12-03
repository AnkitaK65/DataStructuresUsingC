/*
    Example 22: Using std::vector in C++
    -----------------------------------
    Purpose:
    - Demonstrate the usage of C++ STL vector and its commonly used functions

    What is STL?
    ------------
    STL → Standard Template Library
    • A set of pre-written classes and functions used for common data structures
        and algorithms.
    • 4 Major Components of STL:
            1) Containers → Store data (vector, list, map, set, etc.)
            2) Algorithms → Sorting, searching, etc. (sort(), reverse(), find() etc.)
            3) Iterators → Pointer-like objects used for traversing containers
            4) Functors → Function objects used with algorithms

    What is a Vector?
    -----------------
    • A dynamic array that can grow/shrink automatically
    • Provides fast random access (like arrays)
    • Memory is automatically managed internally
    • Defined in <vector> header

    Commonly Used Vector Functions:
    -------------------------------
    vector<int> v;       → Declare vector
    v.push_back(x);      → Add element at end
    v.pop_back();        → Remove last element
    v.size();            → Returns number of elements
    v.capacity();        → Shows allocated storage
    v.at(i);             → Safe element access with bounds checking
    v[i];                → Fast access (no bounds checking)
    v.front();           → First element
    v.back();            → Last element
    v.insert(it, x);     → Insert at position
    v.erase(it);         → Remove element at position
    v.clear();           → Removes all elements
    v.empty();           → Check if vector is empty

    Note:
    Iterators are used for safe traversal of vectors.
*/

#include <iostream>
#include <vector>
#include <algorithm>  // sort(), reverse() etc.

using namespace std;

int main() {

    // Create a vector of integers
    vector<int> v;

    // Insert elements using push_back()
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    cout << "Vector elements: ";
    for(int x : v)   // Range-based for loop (C++11 feature)
        cout << x << " ";
    cout << endl;

    // Access first & last elements
    cout << "Front: " << v.front() << endl;
    cout << "Back : " << v.back() << endl;

    // Insert and erase using iterators
    v.insert(v.begin() + 2, 99);  // Insert 99 at index 2
    cout << "After insertion: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    v.erase(v.begin() + 1);  // Remove element at index 1
    cout << "After erase: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // Display size and capacity
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    // Safe access using at()
    cout << "Element at index 2: " << v.at(2) << endl;

    // Sorting the vector (uses <algorithm>)
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // Removing last element
    v.pop_back();
    cout << "After pop_back: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // Clearing the vector
    v.clear();
    if(v.empty())
        cout << "Vector is now empty!" << endl;

    return 0;
}

/*
Output:
Vector elements: 10 20 30 40 
Front: 10
Back : 40
After insertion: 10 20 99 30 40 
After erase: 10 99 30 40 
Size: 4
Capacity: 8
Element at index 2: 30
Sorted: 10 30 40 99 
After pop_back: 10 30 40 
Vector is now empty!
*/