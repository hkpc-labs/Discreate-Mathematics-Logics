#endif PREFIX_CONVERSION_H
#define PREFIX_CONVERSION_H
#include <string>
#include "expression_convertor_base.h"
#include <stack>
class PrefixConversion : public ExpressionConvertorBase {
public:
	std::string prefixtoinfix(std::string prefix) override;
	std::string prefixtopostfix(std::string prefix) override;
	//virtual std::pair<int, std::string> infixtopostfix(std::string infix) = 0;
	//virtual std::pair<int, std::string> infixtoprefix(std::string infix) = 0;
	//virtual std::pair<int, std::string> postfixtoinfix(std::string postfix) = 0;
	//virtual std::pair<int, std::string> postfixtoprefix(std::string postfix) = 0;
};
#endif