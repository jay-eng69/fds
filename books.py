# Function to remove duplicate entries based on book ID
def delet(a):
    ans = []
    seen = set()
    for item in a:
        if item[0] not in seen:
            ans.append(item)
            seen.add(item[0])
    return ans

# Function to count books with cost greater than 500 and create a list of books with cost less than or equal to 500
def count(a):
    count_above_500 = 0
    less_than_500 = []
    for i in a:
        if int(i[1]) > 500:
            count_above_500 += 1
        else:
            less_than_500.append(i)
    return count_above_500, less_than_500

# Function to sort books in ascending order based on cost
def sort(a):
    ans = a.copy()
    for i in range(len(ans)):
        for j in range(0, len(ans) - i - 1):
            if int(ans[j][1]) > int(ans[j + 1][1]):  # Compare costs as integers
                ans[j], ans[j + 1] = ans[j + 1], ans[j]
    return ans

# Input number of books
n = int(input("ENTER THE NO OF BOOKS: "))
books = []

# Input book details (ID and cost)
for i in range(n):
    a = input(f"ENTER THE ID OF BOOK {i + 1}: ")
    b = input(f"ENTER THE COST OF BOOK {i + 1}: ")
    books.append([a, b])

# Display original list of books
print("ORIGINAL LIST:", books)

# Remove duplicate entries based on book ID
books_no_duplicates = delet(books)
print("DELETE THE DUPLICATE ENTRIES:", books_no_duplicates)

# Sort books in ascending order based on cost
sorted_books = sort(books_no_duplicates)
print("DISPLAY BOOK IN ASCENDING ORDER BASED ON COST OF BOOK:", sorted_books)

# Count books with cost greater than 500 and create a new list for books with cost less than or equal to 500
tup = count(books_no_duplicates)
print("COUNT NO OF BOOKS WITH COST MORE THAN 500:", tup[0])
print("COPY BOOKS IN A NEW LIST WHICH HAS COST LESS THAN 500:", tup[1])
