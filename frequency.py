# Input the number of students
n = int(input("Enter the number of students: "))

# Initialize variables
present, total, min_score, max_score, absent = 0, 0, 51, -1, 0
marks = []

# Input marks for each student
for i in range(n):
    temp = input(f"Enter the marks of student {i + 1} or 'AB' if absent: ")
    marks.append(temp)
    if temp != "AB":  # If the student is present
        present += 1
        score = int(temp)
        total += score

        # Update maximum and minimum scores
        if score > max_score:
            max_score = score
        if score < min_score:
            min_score = score
    else:  # If the student is absent
        absent += 1

# Calculate the average score
avg = total / present if present > 0 else 0

# Calculate the frequency of marks
frequency = {}
for mark in marks:
    if mark != "AB":
        mark_int = int(mark)
        if mark_int in frequency:
            frequency[mark_int] += 1
        else:
            frequency[mark_int] = 1

# Determine the marks with the highest frequency
max_freq = 0
most_frequent_marks = []
for mark, freq in frequency.items():
    if freq > max_freq:
        max_freq = freq
        most_frequent_marks = [mark]
    elif freq == max_freq:
        most_frequent_marks.append(mark)

# Print the results
print(f"The average score of the class: {avg}")
print(f"Highest and lowest scores of the class: {max_score} and {min_score}")
print(f"Number of students absent for the test: {absent}")
print(f"Marks with the highest frequency ({max_freq} occurrences): {most_frequent_marks}")
