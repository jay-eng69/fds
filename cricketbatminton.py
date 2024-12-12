# Define a function to compute the union of two lists
def union(a, b):
    ans = a.copy()
    for i in b:
        if i not in a:
            ans.append(i)
    return ans

# Define a function to compute the difference of two lists (a - b)
def minus(a, b):
    ans = []
    for i in a:
        if i not in b:
            ans.append(i)
    return ans

# Define a function to compute the intersection of two lists
def intersection(a, b):
    ans = []
    for i in a:
        if i in b:
            ans.append(i)
    return ans

# Input the lists
u = input("ENTER THE LIST OF STUDENTS (comma-separated): ").split(",")
b = input("ENTER THE BADMINTON LIST (comma-separated): ").split(",")
c = input("ENTER THE CRICKET LIST (comma-separated): ").split(",")
f = input("ENTER THE FOOTBALL LIST (comma-separated): ").split(",")

# Perform computations and print results
# Students who play both cricket and badminton
cricket_and_badminton = intersection(b, c)
print("List of students who play CRICKET and BADMINTON:", cricket_and_badminton)

# Students who play either cricket or badminton but not both
either_cricket_or_badminton = union(
    minus(c, cricket_and_badminton),
    minus(b, cricket_and_badminton)
)
print("List of students who play either CRICKET or BADMINTON but not BOTH:", either_cricket_or_badminton)

# Students who play neither cricket nor badminton
neither_cricket_nor_badminton = minus(minus(u, b), c)
print("Number of students who play neither CRICKET nor BADMINTON:", len(neither_cricket_nor_badminton))

# Students who play cricket and football but not badminton
cricket_and_football_not_badminton = minus(intersection(c, f), b)
print("List of students who play CRICKET and FOOTBALL but not BADMINTON:", cricket_and_football_not_badminton)
