#include "expression_evaluator.h"
#include <stack>
#include <iostream>
#include <cmath>

char* ExpressionEvaluator::evaluatePostfix(const std::string& postfix, TruthTable table) {
    int numRows = table.getNumberofRows();
    char* results = new char[numRows + 1];
    results[numRows] = '\0';

    for (int i = 0; i < numRows; i++) {
        std::stack<char> operandStack;

        for (char c : postfix) {
            if (isalnum(c)) {
                int colIndex = c - 'A';
                operandStack.push(table.getTruthTableIndex(i, colIndex));
            }
            else {
                if (operandStack.size() < 2 && c != '~') {
                    std::cerr << "Error: Not enough operands for operator " << c << std::endl;
                    delete[] results;
                    return nullptr;
                }

                char result;
                switch (c) {
                case '.': {
                    char operand2 = operandStack.top();
                    operandStack.pop();
                    char operand1 = operandStack.top();
                    operandStack.pop();
                    result = (operand1 == 'T' && operand2 == 'T') ? 'T' : 'F';
                    operandStack.push(result);
                    break;
                }
                case '+': {
                    char operand2 = operandStack.top();
                    operandStack.pop();
                    char operand1 = operandStack.top();
                    operandStack.pop();
                    result = (operand1 == 'T' || operand2 == 'T') ? 'T' : 'F';
                    operandStack.push(result);
                    break;
                }
                case '~': {
                    char operand = operandStack.top();
                    operandStack.pop();
                    result = (operand == 'T') ? 'F' : 'T';
                    operandStack.push(result);
                    break;
                }
                default: {
                    std::cerr << "Error: Invalid operator " << c << std::endl;
                    delete[] results;
                    return nullptr;
                }
                }
            }
        }

        if (operandStack.size() == 1) {
            results[i] = operandStack.top();
        }
        else {
            std::cerr << "Error: Invalid postfix expression." << std::endl;
            delete[] results;
            return nullptr;
        }
    }

    return results;
}

void ExpressionEvaluator::printResults(const char* results, int rows) {
    if (results == nullptr) {
        std::cerr << "Error: Cannot print null results." << std::endl;
        return;
    }
    if(results != nullptr) {
        std::cout << "Evaluation Results:" << std::endl;
        for (int i = 0; i < rows; i++) {
			if (results != nullptr) {
				std::cout << "Row " << i + 1 << ": " << results[i] << std::endl;
			}
        }
		delete[] results;
    }
}