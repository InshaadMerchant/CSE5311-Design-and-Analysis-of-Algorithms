#include <stdio.h>

int removeDuplicates(int *arr, int n) 
{
    if (n == 0) 
    {
        return 0;
    }    
    int index = 1;  // Index to place the next unique element

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] != arr[i - 1]) 
        {
            arr[index++] = arr[i];
        }
    }

    return index;  // New size of the array with duplicates removed
}

int main(void) 
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before removing duplicates: [");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    int newSize = removeDuplicates(arr, n);
    printf("Array after removing duplicates: [");
    for (int i = 0; i < newSize; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    return 0;
}
