#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Operators with no precedence
}

// Function to convert an infix expression to a postfix expression
string infixToPostfix(const string& infix) {
    stack<char> opStack; // Stack to hold operators and parentheses
    string postfix;      // Resulting postfix expression

    for (size_t i = 0; i < infix.size(); ++i) {
        char ch = infix[i];
        if (isalnum(ch)) { // If the character is an operand
            postfix += ch; // Add operands directly to the postfix expression
        } else if (ch == '(') {
            opStack.push(ch); // Push '(' onto the stack
        } else if (ch == ')') {
            // Pop from stack until '(' is encountered
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove the '(' from the stack
        } else { // The character is an operator
            // Pop operators from the stack with higher or equal precedence
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch); // Push the current operator onto the stack
        }
    }

    // Pop remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix; // Return the final postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> valueStack; // Stack to hold values during evaluation

    for (size_t i = 0; i < postfix.size(); ++i) {
        char ch = postfix[i];
        if (isdigit(ch)) { // If the character is a digit (operand)
            valueStack.push(ch - '0'); // Convert char to int and push onto the stack
        } else { // The character is an operator
            // Pop two operands from the stack
            int right = valueStack.top();
            valueStack.pop();
            int left = valueStack.top();
            valueStack.pop();

            // Perform the operation based on the operator
            switch (ch) {
                case '+':
                    valueStack.push(left + right);
                    break;
                case '-':
                    valueStack.push(left - right);
                    break;
                case '*':
                    valueStack.push(left * right);
                    break;
                case '/':
                    if (right != 0)
                        valueStack.push(left / right);
                    else {
                        cout << "Error: Division by zero" << endl;
                        return 0; // Return immediately on error
                    }
                    break;
            }
        }
    }

    return valueStack.top(); // The final result is the last item on the stack
}

int main() {
    string infix;

    // Input: Infix expression
    cout << "Enter an infix expression (e.g., A+B*C): ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate the postfix expression (assuming single-digit operands)
    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}
