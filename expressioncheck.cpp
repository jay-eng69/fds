#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if the brackets in the expression are balanced
bool isBalanced(const string& expression) {
    stack<char> stack; // Stack to store opening brackets

    for (char ch : expression) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // Handle closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty, the expression is unbalanced
            if (stack.empty()) {
                return false;
            }
            // Check if the top of the stack matches the current closing bracket
            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty, all brackets were properly matched
    return stack.empty();
}

int main() {
    string expression;

    // Get input from the user
    cout << "Enter an expression: ";
    getline(cin, expression);

    // Check if the expression is balanced
    if (isBalanced(expression)) {
        cout << "VALID EXPRESSION" << endl;
    } else {
        cout << "INVALID EXPRESSION" << endl;
    }

    return 0;
}
