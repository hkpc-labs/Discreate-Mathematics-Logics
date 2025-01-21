#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H
#include <string>
#include <iostream>
#include <stack>
#include "truth_table.h"
class ExpressionEvaluator {
public:
	char* evaluatePostfix(const std::string& postfix, TruthTable table);
	void printResults(const char* result, int rows);
};
#endif