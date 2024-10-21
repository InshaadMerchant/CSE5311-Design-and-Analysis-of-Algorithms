#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the doubly linked list
typedef struct Node {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Hash table structure
typedef struct {
    Node** table;
    int capacity;
    int size;
    float load_factor;
} HashTable;

// Function to perform multiplication hash
int multiplication_hash(int key, int capacity) {
    const double A = 0.6180339887; // (sqrt(5) - 1) / 2
    double temp = (double)key * A;
    temp = temp - (int)temp;  // Get fractional part
    return (int)(capacity * temp);
}

// Function to perform division hash
int division_hash(int key, int capacity) {
    return key % capacity;
}

// Function to create a new node
Node* create_node(int key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to create a new hash table
HashTable* create_hash_table(int initial_capacity, float load_factor) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    ht->capacity = initial_capacity;
    ht->size = 0;
    ht->load_factor = load_factor;
    
    ht->table = (Node**)calloc(initial_capacity, sizeof(Node*));
    if (ht->table == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(ht);
        exit(1);
    }
    
    printf("Hash table created with initial capacity: %d\n", initial_capacity);
    return ht;
}

// Function to resize the hash table
void resize_hash_table(HashTable* ht, bool grow) {
    int old_capacity = ht->capacity;
    Node** old_table = ht->table;
    
    // Update capacity
    ht->capacity = grow ? ht->capacity * 2 : ht->capacity / 2;
    ht->table = (Node**)calloc(ht->capacity, sizeof(Node*));
    
    if (ht->table == NULL) {
        fprintf(stderr, "Memory allocation failed during resize!\n");
        exit(1);
    }
    
    printf("Resizing hash table from %d to %d\n", old_capacity, ht->capacity);
    
    // Rehash all existing elements using both hash methods
    for (int i = 0; i < old_capacity; i++) {
        Node* current = old_table[i];
        while (current != NULL) {
            Node* next = current->next;
            
            // Combine multiplication and division hash
            int mult_hash = multiplication_hash(current->key, ht->capacity);
            int div_hash = division_hash(current->key, ht->capacity);
            int new_index = (mult_hash + div_hash) / 2;  // Average of both methods
            
            current->next = ht->table[new_index];
            current->prev = NULL;
            if (ht->table[new_index] != NULL) {
                ht->table[new_index]->prev = current;
            }
            ht->table[new_index] = current;
            
            current = next;
        }
    }
    
    free(old_table);
}

// Function to insert a key-value pair
void hash_table_put(HashTable* ht, int key, int value) {
    // Check if resize needed
    if ((float)(ht->size + 1) / ht->capacity > ht->load_factor) {
        resize_hash_table(ht, true);
    }
    
    // Use both hash methods
    int mult_hash = multiplication_hash(key, ht->capacity);
    int div_hash = division_hash(key, ht->capacity);
    int index = (mult_hash + div_hash) / 2;  // Average of both methods
    
    // Check if key already exists
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            printf("Updated key %d with value %d\n", key, value);
            return;
        }
        current = current->next;
    }
    
    // Create new node and insert at beginning of chain
    Node* new_node = create_node(key, value);
    new_node->next = ht->table[index];
    if (ht->table[index] != NULL) {
        ht->table[index]->prev = new_node;
    }
    ht->table[index] = new_node;
    ht->size++;
    printf("Inserted key %d with value %d\n", key, value);
}

// Function to get a value by key
bool hash_table_get(HashTable* ht, int key, int* value) {
    int mult_hash = multiplication_hash(key, ht->capacity);
    int div_hash = division_hash(key, ht->capacity);
    int index = (mult_hash + div_hash) / 2;
    
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to remove a key-value pair
bool hash_table_remove(HashTable* ht, int key) {
    int mult_hash = multiplication_hash(key, ht->capacity);
    int div_hash = division_hash(key, ht->capacity);
    int index = (mult_hash + div_hash) / 2;
    
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            free(current);
            ht->size--;
            printf("Removed key %d\n", key);
            
            // Check if shrink needed
            if (ht->size < ht->capacity / 4 && ht->capacity > 16) {
                resize_hash_table(ht, false);
            }
            return true;
        }
        current = current->next;
    }
    printf("Key %d not found for removal\n", key);
    return false;
}

// Function to print the hash table
void print_hash_table(HashTable* ht) {
    printf("\n=== Hash Table Contents ===\n");
    printf("Size: %d, Capacity: %d\n", ht->size, ht->capacity);
    for (int i = 0; i < ht->capacity; i++) {
        if (ht->table[i] != NULL) {
            printf("Bucket %d: ", i);
            Node* current = ht->table[i];
            while (current != NULL) {
                printf("(%d:%d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("========================\n\n");
}

// Function to free the hash table
void free_hash_table(HashTable* ht) {
    for (int i = 0; i < ht->capacity; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(ht->table);
    free(ht);
    printf("Hash table freed successfully\n");
}

int main() {
    printf("Starting Hash Table Demo\n\n");

    // 1. Create hash table
    printf("=== Creating Hash Table ===\n");
    HashTable* ht = create_hash_table(16, 0.75);
    
    // 2. Test insertions
    printf("\n=== Testing Insertions ===\n");
    hash_table_put(ht, 5, 500);
    hash_table_put(ht, 2, 200);
    hash_table_put(ht, 9, 900);
    hash_table_put(ht, 15, 1500);
    hash_table_put(ht, 28, 2800);
    print_hash_table(ht);
    
    // 3. Test retrieval
    printf("=== Testing Retrieval ===\n");
    int value;
    if (hash_table_get(ht, 5, &value)) {
        printf("Retrieved value for key 5: %d\n", value);
    } else {
        printf("Key 5 not found\n");
    }
    
    if (hash_table_get(ht, 100, &value)) {
        printf("Retrieved value for key 100: %d\n", value);
    } else {
        printf("Key 100 not found\n");
    }
    
    // 4. Test removal
    printf("\n=== Testing Removal ===\n");
    hash_table_remove(ht, 2);
    hash_table_remove(ht, 15);
    print_hash_table(ht);
    
    // 5. Test resizing
    printf("=== Testing Resizing ===\n");
    // Add more elements to trigger resize
    for (int i = 0; i < 20; i++) {
        hash_table_put(ht, i + 30, (i + 30) * 100);
    }
    print_hash_table(ht);
    
    // 6. Test shrinking
    printf("=== Testing Shrinking ===\n");
    // Remove elements to trigger shrink
    for (int i = 0; i < 15; i++) {
        hash_table_remove(ht, i + 30);
    }
    print_hash_table(ht);
    
    // 7. Clean up
    printf("=== Cleaning Up ===\n");
    free_hash_table(ht);
    
    printf("\nHash Table Demo Complete\n");
    return 0;
}