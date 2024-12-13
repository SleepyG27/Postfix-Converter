#include <iostream>
#include <fstream>
#include "InfixToPostfix.h"

int main() {
    InfixToPostfix converter;
    std::string infixExpression;

    // Read input from the file (InfixData.txt)
    std::ifstream inputFile("InfixData.txt");

    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Read each line (infix expression) and process it
    while (std::getline(inputFile, infixExpression)) {
        // Print the original infix expression
        std::cout << "Infix Expression: " << infixExpression << std::endl;

        // Convert the infix expression to postfix
        converter.convert(infixExpression);

        // Print the resulting postfix expression
        std::cout << "Postfix Expression: " << converter.getPostfix() << std::endl;
    }

    inputFile.close();  // Close the file

    return 0;
}
