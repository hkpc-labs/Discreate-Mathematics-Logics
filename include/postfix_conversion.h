#endif POSTFIX_CONVERSION_H
#define POSTFIX_CONVERSION_H
#include <string>
#include "expression_convertor_base.h"
#include <stack>
class PostfixConversion : public ExpressionConvertorBase {
public:
	static std::string postfixtoinfix(std::string postfix) override;
	std::string postfixtoprefix(std::string postfix) override;

	//virtual std::pair<int, std::string> infixtopostfix(std::string infix) = 0;
	//virtual std::pair<int, std::string> infixtoprefix(std::string infix) = 0;

	//virtual std::pair<int, std::string> prefixtoinfix(std::string prefix) = 0;
	//virtual std::pair<int, std::string> prefixtopostfix(std::string prefix) = 0;
#endif // POSTFIX_CONVERSION_H