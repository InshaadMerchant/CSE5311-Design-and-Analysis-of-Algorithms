import random

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def merge_arrays(arrays):
    merged_array = []
    for array in arrays:
        merged_array.extend(array)
    merge_sort(merged_array)
    return merged_array


def main():
    arr1 = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]
    arr2 = [[1, 3, 7], [2, 4, 8], [9, 10, 11]]

    mergedarr1 = merge_arrays(arr1)
    mergedarr2 = merge_arrays(arr2)
    print("Unsorted Array: ")
    print(arr1)
    print(arr2)
    print("Merged Sorted Array:")
    print(mergedarr1)
    print(mergedarr2)

if __name__ == "__main__":
    main()
