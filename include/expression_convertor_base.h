#ifndef EXPRESSION_CONVERTOR_BASE_H
#define EXPRESSION_CONVERTOR_BASE_H
#include <string>
#include <iostream>
class ExpressionConvertorBase {
protected:
	int precedence(char c);
public:
	virtual std::pair<int, std::string> infixtopostfix(std::string infix) = 0;
	virtual std::pair<int, std::string> infixtoprefix(std::string infix) = 0;
	virtual std::pair<int, std::string> postfixtoinfix(std::string postfix) = 0;
	virtual std::pair<int, std::string> postfixtoprefix(std::string postfix) = 0;
	virtual std::pair<int, std::string> prefixtoinfix(std::string prefix) = 0;
	virtual std::pair<int, std::string> prefixtopostfix(std::string prefix) = 0;
};
#endif