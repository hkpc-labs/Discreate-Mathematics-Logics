#include <iostream>
#include "../include/truth_table.h"
#include <string>
#include "../include/infix_conversion.h"
#include <utility>
#include "../include/expression_evaluator.h"

void menu() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "\t\tLOGIC EXPRESSION EVALUATOR" << std::endl;
    std::cout << "*********************************************" << std::endl;
    std::cout << "1. Infix to Postfix" << std::endl;
    std::cout << "2. Infix to Prefix" << std::endl;
    std::cout << "3. Generate Truth Table" << std::endl;
    std::cout << "4. Evaluate Postfix" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "*********************************************" << std::endl;
    std::cout << "Enter your choice: ";
}

void generatetable(int n) {
    TruthTable tt;
    tt.generateTruthTable(n);
    tt.printTruthTable();
}

void eval(std::string infix) {
    std::cout << "Enter the infix expression: ";
    std::cin >> infix;
    InfixConversion* ic = new InfixConversion();
    std::pair<int, std::string> p = ic->infixtopostfix(infix);
    int n = p.first;
    std::cout << "No of variables: " << n << std::endl;
    std::cout << "Postfix Expression: " << p.second << std::endl;
    std::cout << "Truth Table: " << std::endl;
    TruthTable tt;
    tt.generateTruthTable(n);
    tt.printTruthTable();
    ExpressionEvaluator ee;
    char* results = ee.evaluatePostfix(p.second, tt);
    if (results != nullptr) {
        ee.printResults(results, tt.getNumberofRows());
       // delete[] results;
    }
}

void infixtopostfix(std::string infix) {
    InfixConversion i;
    std::pair<int, std::string> p = i.infixtopostfix(infix);
    std::cout << "No of variables: " << p.first << std::endl;
    std::cout << "Postfix Expression: " << p.second << std::endl;
}

void infixtoprefix(std::string infix) {
    InfixConversion i;
    std::pair<int, std::string> p = i.infixtoprefix(infix);
    std::cout << "No of variables: " << p.first << std::endl;
    std::cout << "Prefix Expression: " << p.second << std::endl;
}

int main() {
    int choice;
    do {
        menu();
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::string infix;
            std::cout << "Enter the infix expression: ";
            std::cin >> infix;
            infixtopostfix(infix);
            break;
        }
        case 2: {
            std::string infix;
            std::cout << "Enter the infix expression: ";
            std::cin >> infix;
            infixtoprefix(infix);
            break;
        }
        case 3: {
            int n;
            std::cout << "Enter the number of variables: ";
            std::cin >> n;
            generatetable(n);
            break;
        }
        case 4: {
            std::string infix;
            eval(infix);
            break;
        }
        case 5:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
    return 0;
}
