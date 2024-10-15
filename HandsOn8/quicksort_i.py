def swap(a, b):
    return b, a

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = swap(arr[j], arr[i])
    arr[i+1], arr[high] = swap(arr[high], arr[i+1])
    return i + 1

def quicksort_i(arr, low, high, k):
    if low <= high:
        pi = partition(arr, low, high)
        
        #if the pivot = k-th smallest element
        if pi == k:
            return arr[pi]
        #if the k-th smallest is on the left side of the pivot
        elif pi > k:
            return quicksort_i(arr, low, pi - 1, k)
        #if the k-th smallest is on the right side of the pivot
        else:
            return quicksort_i(arr, pi + 1, high, k)
    
    return None 

def main():
    n = int(input("Enter the number of elements: "))
    print(f"Enter {n} elements (separated by commas): ", end="")
    arr = list(map(int, input().strip().split(',')))  # Split by commas

    k = int(input("Enter the order statistic to find (smallest index is 0th): "))

    if k < 0 or k >= n:
        print("Index out of bounds.")
        return

    print("Original array:", ' '.join(map(str, arr)))
    result = quicksort_i(arr, 0, n - 1, k)
    print(f"The {k}-th order statistic is: {result}")

if __name__ == "__main__":
    main()
