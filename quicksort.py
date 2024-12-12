def quicksort(arr):
    """Sort the array using the quicksort algorithm."""
    if len(arr) <= 1:
        return arr  # Base case: single element or empty list is already sorted
    else:
        pivot = arr[0]  # Choose the first element as the pivot
        # Partition the array into three parts
        left = [x for x in arr[1:] if x < pivot]  # Elements less than pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to pivot
        right = [x for x in arr[1:] if x > pivot]  # Elements greater than pivot
        # Recursively sort the left and right partitions and concatenate
        return quicksort(left) + middle + quicksort(right)

if __name__ == "__main__":
    # Input the number of percentages
    m = int(input("ENTER THE NUMBER OF PERCENTAGES: "))
    percentages = []
    
    # Input each percentage
    for i in range(m):
        n = int(input(f"ENTER THE PERCENTAGE FOR STUDENT {i + 1}: "))
        percentages.append(n)

    # Sort the percentages using quicksort
    sorted_percentages = quicksort(percentages)
    print("PERCENTAGES IN ASCENDING ORDER:", sorted_percentages)

    # Extract the top five percentages (highest scores)
    top_five_percentages = sorted_percentages[-5:]  # Get the last 5 elements
    print("TOP FIVE PERCENTAGES ARE:", top_five_percentages[::-1])  # Display in descending order

    # Display percentages in descending order
    top_five_percentages.reverse()
    print("PERCENTAGES IN DESCENDING ORDER:", top_five_percentages)
