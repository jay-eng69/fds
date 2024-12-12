def insertion_sort(arr):
    """Sort the array using the insertion sort algorithm."""
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1] that are greater than key to one position ahead
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def shell_sort(arr):
    """Sort the array using the shell sort algorithm."""
    n = len(arr)
    gap = n // 2  # Initialize the gap
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Perform a gapped insertion sort
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp  # Place temp in its correct position
        gap //= 2  # Reduce the gap size
    return arr

def display_top_five(arr):
    """Display the top 5 scores."""
    top_five = sorted(arr, reverse=True)[:5]  # Sort in descending order and take top 5
    print("Top 5 scores:")
    for score in top_five:
        print(f"{score:.2f}")

if __name__ == "__main__":
    # Input the number of percentages
    m = int(input("Enter total number of marks: "))
    percentages = []
    
    # Input each percentage
    for k in range(m):
        n = float(input(f"Enter the marks for student {k + 1}: "))
        percentages.append(n)

    print("Original percentages:", percentages)

    # Sorting using insertion sort
    sorted_per_insertion = insertion_sort(percentages.copy())
    print("Sorted percentages using insertion sort:", sorted_per_insertion)
    display_top_five(sorted_per_insertion)

    # Sorting using shell sort
    sorted_per_shell = shell_sort(percentages.copy())
    print("\nSorted percentages using shell sort:", sorted_per_shell)
    display_top_five(sorted_per_shell)
