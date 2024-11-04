#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int* data;     // Pointer to the data array
    size_t sz;     // Number of elements in the vector
    size_t cap;    // Allocated capacity of the array
} Vector;

// Function to resize the internal array
void resize(Vector *vec, size_t new_cap) {
    printf("Resizing from capacity %zu to %zu\n", vec->cap, new_cap);
    int* new_data = (int*) malloc(new_cap * sizeof(int)); // Allocate new memory
    for (size_t i = 0; i < vec->sz; ++i) {
        new_data[i] = vec->data[i];  // Copy existing elements
    }
    free(vec->data);                // Free old memory
    vec->data = new_data;           // Update data pointer
    vec->cap = new_cap;             // Update capacity
}

// Function to initialize the vector
void Vector_init(Vector *vec) {
    vec->data = NULL;
    vec->sz = 0;
    vec->cap = 0;
}

// Function to destroy the vector
void Vector_destroy(Vector *vec) {
    free(vec->data);
}

// Function to add an element at the end
void push_back(Vector *vec, int val) {
    if (vec->sz == vec->cap) {      // Need to resize
        size_t new_cap = vec->cap == 0 ? 1 : vec->cap * 2;
        resize(vec, new_cap);
    }
    vec->data[vec->sz++] = val;     // Add new element
}

// Function to remove the last element
void pop_back(Vector *vec) {
    if (vec->sz > 0) {
        --vec->sz;                  // Decrease size
    }
}

// Function to get the value at a specific index
int get(Vector *vec, size_t index) {
    return vec->data[index];
}

// Function to get the current size of the vector
size_t size(const Vector *vec) {
    return vec->sz;
}

// Function to get the current capacity of the vector
size_t capacity(const Vector *vec) {
    return vec->cap;
}

// Function to print the elements in the vector
void print(const Vector *vec) {
    for (size_t i = 0; i < vec->sz; ++i) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

int main() {
    Vector vec;
    Vector_init(&vec);
    push_back(&vec, 10);
    push_back(&vec, 20);
    push_back(&vec, 30);
    push_back(&vec, 40); // This will trigger a resize

    printf("Array elements: ");
    print(&vec);
    printf("Size: %zu, Capacity: %zu\n", size(&vec), capacity(&vec));

    pop_back(&vec);
    printf("Array elements after pop_back: ");
    print(&vec);
    printf("Size: %zu, Capacity: %zu\n", size(&vec), capacity(&vec));

    Vector_destroy(&vec);
    return 0;
}
