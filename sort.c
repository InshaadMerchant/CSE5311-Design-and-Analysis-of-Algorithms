#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)     
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void populate_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 5000;
    }
}

int main() {
    int sizes[] = {5, 10, 20, 100, 500, 1000, 5000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    clock_t start, end;
    double cpu_time_used[num_sizes][3]; // 0 for Insertion, 1 for Selection, 2 for Bubble

    printf("Size\t\tInsertion\tSelection\tBubble\n");
    for (int i = 0; i < num_sizes; i++) {
        int *arr = malloc(sizes[i] * sizeof(int));
        
        populate_array(arr, sizes[i]);
        start = clock();
        insertionSort(arr, sizes[i]);
        end = clock();
        cpu_time_used[i][0] = ((double) (end - start)) / CLOCKS_PER_SEC;

        populate_array(arr, sizes[i]);
        start = clock();
        selectionSort(arr, sizes[i]);
        end = clock();
        cpu_time_used[i][1] = ((double) (end - start)) / CLOCKS_PER_SEC;

        populate_array(arr, sizes[i]);
        start = clock();
        bubbleSort(arr, sizes[i]);
        end = clock();
        cpu_time_used[i][2] = ((double) (end - start)) / CLOCKS_PER_SEC;

        free(arr);
    }

    for (int i = 0; i < num_sizes; i++) {
        printf("%d\t\t%f\t%f\t%f\n", sizes[i], cpu_time_used[i][0], cpu_time_used[i][1], cpu_time_used[i][2]);
    }

    return 0;
}
