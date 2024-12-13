#include "InfixToPostfix.h"
#include <cctype>
#include <stack>

// Helper function to check operator precedence
int InfixToPostfix::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to get the postfix expression
std::string InfixToPostfix::getPostfix() {
    return postfixExpression;
}

// Convert infix expression to postfix
void InfixToPostfix::convert(const std::string& infix) {
    std::stack<char> operatorStack;
    postfixExpression.clear();  // Clear previous postfix string

    for (char ch : infix) {
        if (isalpha(ch)) {
            // If the character is an operand, append it to the postfix expression
            postfixExpression += ch;
        }
        else if (ch == '(') {
            // If the character is '(', push it onto the stack
            operatorStack.push(ch);
        }
        else if (ch == ')') {
            // If the character is ')', pop from stack until '(' is found
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();  // Pop the '(' from the stack
        }
        else if (ch == ' ') {
            // Ignore spaces
            continue;
        }
        else {
            // If the character is an operator, pop operators from the stack
            
            while (!operatorStack.empty() && precedence(ch) <= precedence(operatorStack.top())) {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);  // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }
}
