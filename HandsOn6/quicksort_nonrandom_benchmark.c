// Inshaad Merchant 1001861293
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <time.h>

void swap(int *SwapA, int *SwapB)
{
    int temp = *SwapA;
    *SwapA = *SwapB;
    *SwapB = temp;
}

int partition(int A[], int low, int high, int pivotType)
{
    int pivotIndex = pivotType ? high : (low + rand() % (high - low + 1));
    int pivot = A[pivotIndex];
    swap(&A[pivotIndex], &A[high]);  // Move the pivot to the end for consistency
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)  // Exclude the pivot itself
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);  // Place the pivot in its correct position
    return (i + 1);
}

void QuickSort(int MyArray[], int low, int high, int pivotType)
{
    if (low < high)
    {
        int ndx = partition(MyArray, low, high, pivotType);
        QuickSort(MyArray, low, ndx - 1, pivotType);  // Recur on the left side
        QuickSort(MyArray, ndx + 1, high, pivotType); // Recur on the right side
    }
}

void FillArray(int arr[], int size, int caseType) {
    for (int i = 0; i < size; i++) {
        switch (caseType) {
            case 0: // Worst case (ascending sorted)
                arr[i] = i;
                break;
            case 1: // Average case (random)
                arr[i] = rand() % size;
                break;
            case 2: // Best case (for demonstration)
                arr[i] = rand() % size; // Still using random for lack of a better automatic method
                break;
        }
    }
}

int main(int argc , char *argv[]) 
{ 

    // QUICK SORT NON-RANDOM VERSION

    int sizes[] = {10, 50, 100, 1000, 5000, 10000, 20000, 30000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    srand(time(NULL));

    for (int i = 0; i < num_sizes; i++) 
    {
        int n = sizes[i];
        int *MyArray = malloc(n * sizeof(int));

        printf("Array size: %d\n", n);
        for (int caseType = 0; caseType < 3; caseType++) 
        {
            FillArray(MyArray, n, caseType);
            clock_t start = clock();
            QuickSort(MyArray, 0, n - 1, 1);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;

            printf("Time for ");
            if (caseType == 0)
            {
                printf("worst case: ");
            }
            else if (caseType == 1) 
            {
                printf("average case: ");
            }
            else
            {   
                printf("best case: ");
            }
            printf("%f seconds\n", time);
        }
        free(MyArray);
        printf("\n");
    }
    return 0; 
} 
