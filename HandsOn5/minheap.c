#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void** elements;    // Array of pointers to hold the elements of the heap
    int size;           // Current size of the heap
    int capacity;       // Maximum capacity of the heap
    int (*cmp)(const void*, const void*); // Function pointer for comparing elements
} MinHeap;

int int_compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void print_int(void* a) {
    printf("%d ", *(int*)a);
}

MinHeap* create_min_heap(int capacity, int (*cmp)(const void*, const void*)) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->elements = malloc(sizeof(void*) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    heap->cmp = cmp;
    return heap;
}

void build_min_heap(MinHeap* heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

void heapify(MinHeap* heap, int i) {
    int left = (i << 1) + 1;
    int right = (i << 1) + 2;
    int smallest = i;

    if (left < heap->size && heap->cmp(heap->elements[left], heap->elements[smallest]) < 0) {
        smallest = left;
    }
    if (right < heap->size && heap->cmp(heap->elements[right], heap->elements[smallest]) < 0) {
        smallest = right;
    }
    if (smallest != i) {
        void* temp = heap->elements[i];
        heap->elements[i] = heap->elements[smallest];
        heap->elements[smallest] = temp;
        heapify(heap, smallest);
    }
}

void* pop(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    void* root = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

void insert(MinHeap* heap, void* element) {
    if (heap->size == heap->capacity) return; // Heap full

    heap->size++;
    int i = heap->size - 1;
    heap->elements[i] = element;

    while (i != 0 && heap->cmp(heap->elements[(i-1)>>1], heap->elements[i]) > 0) {
        void* temp = heap->elements[i];
        heap->elements[i] = heap->elements[(i-1)>>1];
        heap->elements[(i-1)>>1] = temp;
        i = (i-1)>>1;
    }
}

void print_heap(MinHeap* heap, void (*print_element)(void*)) {
    for (int i = 0; i < heap->size; i++) {
        print_element(heap->elements[i]);
    }
    printf("\n");
}

void free_heap(MinHeap* heap) {
    free(heap->elements);
    free(heap);
}

int main() {
    int a[] = {15,10,12,5,2,1,6};
    int n = sizeof(a) / sizeof(a[0]);
    
    MinHeap* heap = create_min_heap(n, int_compare);

    for (int i = 0; i < n; i++) {
        insert(heap, &a[i]);
    }

    build_min_heap(heap);
    print_heap(heap, print_int);

    int* min = pop(heap);
    if (min) printf("Popped min: %d\n", *min);
    print_heap(heap, print_int);

    free_heap(heap);
    return 0;
}
