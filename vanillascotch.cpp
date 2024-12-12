#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    string name;  // Name of the student
    Node* next;   // Pointer to the next node
};

// Function to insert a student into the linked list
void insert(Node*& head, const string& name) {
    Node* newNode = new Node{name, nullptr};
    if (!head) { // If the list is empty
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) { // Traverse to the end
            temp = temp->next;
        }
        temp->next = newNode; // Insert at the end
    }
}

// Function to display the linked list
void display(Node* head) {
    while (head) {
        cout << head->name << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to compute the intersection of two sets
unordered_set<string> intersection(Node* listA, Node* listB) {
    unordered_set<string> setA;  // Set to store names from listA
    unordered_set<string> result; // Set to store intersection result

    // Store names from listA
    while (listA) {
        setA.insert(listA->name);
        listA = listA->next;
    }

    // Check for common names in listB
    while (listB) {
        if (setA.find(listB->name) != setA.end()) {
            result.insert(listB->name); // Add to the result set
        }
        listB = listB->next;
    }

    return result;
}

// Function to compute the union of two sets
unordered_set<string> unionSets(Node* listA, Node* listB) {
    unordered_set<string> result;

    // Add names from listA
    while (listA) {
        result.insert(listA->name);
        listA = listA->next;
    }

    // Add names from listB
    while (listB) {
        result.insert(listB->name);
        listB = listB->next;
    }

    return result;
}

int main() {
    Node* vanillaStudents = nullptr;       // Linked list for vanilla ice-cream lovers
    Node* butterscotchStudents = nullptr;  // Linked list for butterscotch ice-cream lovers
    int totalStudents;

    // Input: Total number of students
    cout << "Enter total number of students: ";
    cin >> totalStudents;
    cin.ignore(); // To ignore newline character

    // Input: Names of students (this can be used for additional logic if needed)
    cout << "Enter names of all students (separated by newlines):\n";
    for (int i = 0; i < totalStudents; ++i) {
        string name;
        getline(cin, name);
        // Store these names in an array or process as needed
    }

    // Input: Students who like vanilla ice-cream
    int n; // Number of vanilla ice-cream lovers
    cout << "Enter number of students who like vanilla ice-cream: ";
    cin >> n;
    cin.ignore();
    cout << "Enter names of students who like vanilla ice-cream:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        insert(vanillaStudents, name);
    }

    // Input: Students who like butterscotch ice-cream
    cout << "Enter number of students who like butterscotch ice-cream: ";
    cin >> n;
    cin.ignore();
    cout << "Enter names of students who like butterscotch ice-cream:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        insert(butterscotchStudents, name);
    }

    // Compute intersection
    unordered_set<string> both = intersection(vanillaStudents, butterscotchStudents);
    cout << "Students who like both vanilla and butterscotch: ";
    for (const auto& name : both) {
        cout << name << " ";
    }
    cout << endl;

    // Compute union
    unordered_set<string> either = unionSets(vanillaStudents, butterscotchStudents);
    cout << "Students who like either vanilla or butterscotch (or both): ";
    for (const auto& name : either) {
        cout << name << " ";
    }
    cout << endl;

    // Calculate and display number of students who like neither
    int neither = totalStudents - either.size();
    cout << "Number of students who like neither vanilla nor butterscotch: " << neither << endl;

    // Free memory for vanillaStudents linked list
    while (vanillaStudents) {
        Node* temp = vanillaStudents;
        vanillaStudents = vanillaStudents->next;
        delete temp;
    }

    // Free memory for butterscotchStudents linked list
    while (butterscotchStudents) {
        Node* temp = butterscotchStudents;
        butterscotchStudents = butterscotchStudents->next;
        delete temp;
    }

    return 0;
}
