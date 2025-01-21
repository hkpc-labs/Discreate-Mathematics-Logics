#ifndef INFIX_CONVERSION_H
#define INFIX_CONVERSION_H
#include <string>
#include <iostream>
#include "expression_convertor_base.h"
#include <stack>
class InfixConversion : public ExpressionConvertorBase {
public:
	virtual std::pair<int, std::string> infixtopostfix(std::string infix) override;
	virtual std::pair<int, std::string> infixtoprefix(std::string infix) override;

	virtual std::pair<int, std::string> postfixtoinfix(std::string postfix) override;
	virtual std::pair<int, std::string> postfixtoprefix(std::string postfix) override;
	virtual std::pair<int, std::string> prefixtoinfix(std::string prefix) override;
	virtual std::pair<int, std::string> prefixtopostfix(std::string prefix) override;
};
#endif