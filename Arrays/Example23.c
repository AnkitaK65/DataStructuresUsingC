/* 
Example 23: Full-Featured Vector (Dynamic Array) Library in C
------------------------------------------------------------
Purpose:
- To implement a powerful Vector data structure like C++ std::vector
- Supports: push, pop, insert, remove, get(at), resize, clear, display, size, capacity

Why Vectors?
------------
- Dynamic size (grows/shrinks as needed)
- Continuous memory like arrays → fast access
- No need to know size at compile time

Major Functions Implemented:
----------------------------
✓ initVector(v)       → Initialize vector
✓ push(v, value)      → Add element at end
✓ pop(v)              → Remove last element
✓ insert(v, index, x) → Insert at specific position
✓ removeAt(v, index)  → Delete element at index
✓ get(v, index)       → Safe element access
✓ resize(v, newCap)   → Increase or change capacity manually
✓ clear(v)            → Remove all elements
✓ display(v)          → Print vector
✓ sizeOf(v)           → Current size
✓ capacityOf(v)       → Allocated capacity

Growth Strategy:
- Capacity doubles when full → Efficient for large inputs
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

// Function: Initialize vector with default capacity = 4
void initVector(Vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = (int*)malloc(v->capacity * sizeof(int));
    if(v->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function: Resize vector capacity
void resize(Vector *v, int newCap) {
    v->capacity = newCap;
    v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    if(v->data == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
}

// Function: Add element at end (push_back)
void push(Vector *v, int value) {
    if(v->size == v->capacity) {
        resize(v, v->capacity * 2); // Double capacity when full
    }
    v->data[v->size++] = value;
}

// Function: Remove element from end (pop_back)
int pop(Vector *v) {
    if(v->size == 0) {
        printf("Vector is empty! Nothing to pop.\n");
        return -1;
    }
    return v->data[--v->size];
}

// Function: Insert element at index
void insert(Vector *v, int index, int value) {
    if(index < 0 || index > v->size) {
        printf("Invalid index!\n");
        return;
    }

    if(v->size == v->capacity)
        resize(v, v->capacity * 2);

    for(int i = v->size; i > index; i--)
        v->data[i] = v->data[i - 1];

    v->data[index] = value;
    v->size++;
}

// Function: Remove element at a given index
void removeAt(Vector *v, int index) {
    if(index < 0 || index >= v->size) {
        printf("Invalid index!\n");
        return;
    }

    for(int i = index; i < v->size - 1; i++)
        v->data[i] = v->data[i + 1];

    v->size--;
}

// Function: Safe access to value at specific index
int get(Vector *v, int index) {
    if(index < 0 || index >= v->size) {
        printf("Index out of bounds!\n");
        return -1;
    }
    return v->data[index];
}

// Function: Display vector contents
void display(Vector *v) {
    printf("Vector: ");
    for(int i = 0; i < v->size; i++)
        printf("%d ", v->data[i]);
    printf("\n");
}

// Function: return current size
int sizeOf(Vector *v) {
    return v->size;
}

// Function: return allocated capacity
int capacityOf(Vector *v) {
    return v->capacity;
}

// Function: Clear vector memory (without destroying structure)
void clear(Vector *v) {
    v->size = 0;
}

// Main function to test all operations
int main() {
    Vector v;
    initVector(&v);

    push(&v, 10);
    push(&v, 20);
    push(&v, 30);
    push(&v, 40);

    display(&v);

    insert(&v, 2, 99); // Insert 99 at index 2
    display(&v);

    removeAt(&v, 1); // Remove element at index 1
    display(&v);

    printf("Element at index 2: %d\n", get(&v, 2));

    printf("Popped: %d\n", pop(&v));

    printf("Size = %d, Capacity = %d\n", sizeOf(&v), capacityOf(&v));

    clear(&v); // Clear elements
    display(&v);

    // Free memory before exit
    free(v.data);

    return 0;
}

/*
Output:
Vector: 10 20 30 40 
Vector: 10 20 99 30 40 
Vector: 10 99 30 40 
Element at index 2: 30
Popped: 40
Size = 3, Capacity = 8
Vector: 
*/