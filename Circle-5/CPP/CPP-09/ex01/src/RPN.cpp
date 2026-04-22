#include "../inc/RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {
}

RPN::~RPN() {
}

bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int a, int b, char op) const {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0) {
				throw std::runtime_error("Division by zero");
			}
			return a / b;
		default:
			throw std::runtime_error("Invalid operator");
	}
}

int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && isOperator(token[0])) {
			if (stack.size() < 2) {
				throw std::runtime_error("Error");
			}

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			int result = performOperation(a, b, token[0]);
			stack.push(result);
		} else {
			if (token.length() != 1 || token[0] < '0' || token[0] > '9') {
				throw std::runtime_error("Error");
			}

			int num = token[0] - '0';
			stack.push(num);
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Error");
	}

	return stack.top();
}

