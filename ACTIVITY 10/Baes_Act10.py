def linearSearch(arr, target):
    """
    Implement linear search algorithm.
    
    Args:
        arr: List of elements to search through
        target: The value to search for
    
    Returns:
        int: Index of target if found, -1 if not found
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


def binarySearch(arr, target):
    """
    Implement binary search algorithm for sorted arrays.
    
    Args:
        arr: Sorted list of elements to search through
        target: The value to search for
    
    Returns:
        int: Index of target if found, -1 if not found
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1


if __name__ == "__main__":
    # Test Linear Search
    print("=== LINEAR SEARCH TESTS ===")
    test_arr = [64, 34, 25, 12, 22, 11, 90]
    
    print(f"Array: {test_arr}")
    print(f"Search for 22: Index {linearSearch(test_arr, 22)}")
    print(f"Search for 12: Index {linearSearch(test_arr, 12)}")
    print(f"Search for 99: Index {linearSearch(test_arr, 99)}")
    
    # Test Binary Search
    print("\n=== BINARY SEARCH TESTS ===")
    sorted_arr = [11, 12, 22, 25, 34, 64, 90]
    
    print(f"Sorted Array: {sorted_arr}")
    print(f"Search for 25: Index {binarySearch(sorted_arr, 25)}")
    print(f"Search for 11: Index {binarySearch(sorted_arr, 11)}")
    print(f"Search for 90: Index {binarySearch(sorted_arr, 90)}")
    print(f"Search for 50: Index {binarySearch(sorted_arr, 50)}")
