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

void PrintArray(int MyArray[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", MyArray[i]);
    }    
    printf("\n");
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
    int MyArray[10] = {5,2,3,10,7,4,18,25,33,47};
    int ArraySize = sizeof(MyArray) / sizeof(MyArray[0]);

    //QUICK SORT RANDOM VERSION

    //Print the unsorted array
	PrintArray(MyArray,ArraySize);

    QuickSort(MyArray, 0, ArraySize-1, 0); // 0 for random pivot, 1 for non-random pivot

    //Print the sorted array
	PrintArray(MyArray,ArraySize);


    // QUICK SORT NON-RANDOM VERSION

    int MyArray2[10] = {5,2,3,10,7,4,18,25,33,47};
    int ArraySize2 = sizeof(MyArray2) / sizeof(MyArray2[0]);

    //QUICK SORT RANDOM VERSION

    //Print the unsorted array
	PrintArray(MyArray2,ArraySize2);

    QuickSort(MyArray2, 0, ArraySize2-1, 1); // 0 for random pivot, 1 for non-random pivot

    //Print the sorted array
	PrintArray(MyArray2,ArraySize2);
    return 0; 
} 
