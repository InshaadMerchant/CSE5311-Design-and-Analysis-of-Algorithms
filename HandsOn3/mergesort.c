// Inshaad Merchant 1001861293
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

void Merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void MergeSort(int arr[], int L, int R)
{
    if (L < R) {
        int M = (L + R) / 2;
        MergeSort(arr, L, M);
        MergeSort(arr, M + 1, R);
        Merge(arr, L, M, R);
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    // MERGE SORT
    int MyArray[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int ArraySize = sizeof(MyArray) / sizeof(MyArray[0]);
    
    // Print the unsorted array
    printf("Unsorted Array: ");
    PrintArray(MyArray, ArraySize);
    
    MergeSort(MyArray, 0, ArraySize - 1);
    
    // Print the sorted array
    printf("Sorted Array: ");
    PrintArray(MyArray, ArraySize);
    
    // END MERGE SORT
    return 0; 
}
