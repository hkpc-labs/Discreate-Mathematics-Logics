#include "../include/infix_conversion.h"
#include <iostream>
#include <stack>
#include <utility>
#include <string>
std::pair<int, std::string> InfixConversion::infixtopostfix(std::string infix) {
	int operands = 0;
	bool found = false;
	std::stack<char> s;
	std::string postfix;
	for (size_t i = 0; i < infix.length(); i++) {
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
			for (size_t j = 0; j < postfix.length(); j++) {
				found = false;
				if (infix[i] == postfix[j]) {
					found = true;
					break;
				}
			}
			if (!found) {
				operands++;
			}
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			s.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			if (!s.empty()) {
				s.pop();
			}
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '.' || infix[i] == '~') {
			while (!s.empty() && precedence(infix[i]) <= precedence(s.top())) {
				postfix += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
		else {
			std::cout << "Invalid infix expression" << std::endl;
			return std::make_pair(0, "");
		}
	}
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return std::make_pair(operands, postfix);
}

std::pair<int, std::string> InfixConversion::infixtoprefix(std::string infix) {
	std::stack<char> s;
	bool check = false;
	int operands = 0;
	std::string rev_infix = std::string(infix.rbegin(), infix.rend());
	std::string prefix;
	for (size_t i = 0; i < rev_infix.length(); i++) {
		if ((rev_infix[i] >= 'a' && rev_infix[i] <= 'z') || (rev_infix[i] >= 'A' && rev_infix[i] <= 'Z')) {
			for (size_t j = 0; j < prefix.length(); j++) {
				check = false;
				if (rev_infix[i] == prefix[j]) {
					check = true;
					break;
				}
			}
			if (!check) {
				operands++;
			}
			prefix += rev_infix[i];
		}
		else if (rev_infix[i] == ')') {
		}
		else if (rev_infix[i] == '(') {
			while (!s.empty() && s.top() != ')') { // Pop until ')' (which was pushed as '(')
				prefix += s.top();
				s.pop();
			}
			if (!s.empty()) {
				s.pop();
			}
		}
		else if (rev_infix[i] == '+' || rev_infix[i] == '-' || rev_infix[i] == '.' || rev_infix[i] == '~') {
			while (!s.empty() && precedence(rev_infix[i]) < precedence(s.top())) {
				prefix += s.top();
				s.pop();
			}
			s.push(rev_infix[i]);
		}
		else {
			std::cout << "Invalid infix expression" << std::endl;
			return std::make_pair(0, "");
		}
	}
	while (!s.empty()) {
		prefix += s.top();
		s.pop();
	}
	std::string final_prefix = std::string(prefix.rbegin(), prefix.rend());
	return std::make_pair(operands, final_prefix);
}
std::pair<int, std::string> InfixConversion::postfixtoinfix(std::string postfix) {
	return std::make_pair(0, "");
}
std::pair<int, std::string> InfixConversion::postfixtoprefix(std::string postfix) {
	return std::make_pair(0, "");
}
std::pair<int, std::string> InfixConversion::prefixtoinfix(std::string prefix) {
	return std::make_pair(0, "");
}
std::pair<int, std::string> InfixConversion::prefixtopostfix(std::string prefix) {
	return std::make_pair(0, "");
}