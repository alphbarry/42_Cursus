#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
private:
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

	bool isOperator(char c) const;
	int performOperation(int a, int b, char op) const;

public:
	RPN();
	~RPN();

	int evaluate(const std::string& expression);
};

#endif

