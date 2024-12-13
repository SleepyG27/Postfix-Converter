#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include <string>
#include <stack>

// Class to convert infix expression to postfix expression
class InfixToPostfix {
private:
    std::string postfixExpression;  // String to hold the postfix expression

    // Helper function to determine the precedence of operators
    int precedence(char op);

public:
    // Function to get the postfix expression
    std::string getPostfix();

    // Convert infix to postfix
    void convert(const std::string& infix);
};

#endif  // INFIX_TO_POSTFIX_H
