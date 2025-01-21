#include "expression_convertor_base.h"
int ExpressionConvertorBase::precedence(char c) {
	if (c == '~') {
		return 3;
	}
	else if (c == '.') {
		return 2;
	}
	else if (c == '+') {
		return 1;
	}
	else {
		return -1;
	}
}