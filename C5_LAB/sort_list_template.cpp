/*
    Question 2:
    Write a program using templates to sort a list of elements. Give the user the option to perform sorting using:
    1. Insertion Sort
    2. Bubble Sort
    3. Selection Sort
*/

#include <iostream>
#include <vector>
using namespace std;

// Template function for Insertion Sort
template <typename T>
void insertionSort(vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        T key = arr[i];
        int j = i - 1;
        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Template function for Bubble Sort
template <typename T>
void bubbleSort(vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if out of order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Template function for Selection Sort
template <typename T>
void selectionSort(vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the current element
        swap(arr[i], arr[minIndex]);
    }
}

// Utility function to print the vector
template <typename T>
void printArray(const vector<T>& arr) {
    for (const T& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    vector<int> arr(n); // Vector to store elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose the sorting method:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Selection Sort\n";
    int choice;
    cin >> choice;

    // Perform sorting based on user's choice
    switch (choice) {
        case 1:
            insertionSort(arr);
            cout << "Sorted using Insertion Sort:\n";
            break;
        case 2:
            bubbleSort(arr);
            cout << "Sorted using Bubble Sort:\n";
            break;
        case 3:
            selectionSort(arr);
            cout << "Sorted using Selection Sort:\n";
            break;
        default:
            cout << "Invalid choice! Exiting.\n";
            return 0;
    }

    // Print the sorted array
    printArray(arr);

    return 0;
}

//Output:
// Enter the number of elements in the list: 5
// Enter 5 elements:
// 12 45 23 8 19
// Choose the sorting method:
// 1. Insertion Sort
// 2. Bubble Sort
// 3. Selection Sort
// 1
// Sorted using Insertion Sort:
// 8 12 19 23 45