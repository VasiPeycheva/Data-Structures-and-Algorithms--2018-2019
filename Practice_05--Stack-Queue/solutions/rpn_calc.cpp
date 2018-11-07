/*
 * A simple calculator based on RPN : https://en.wikipedia.org/wiki/Reverse_Polish_notation. Works only with single digit numbers
 * This file is part of the "Data structures and algorithms" course. FMI 2018/19
 *
 * Author : Ivan Filipov	
 */
#include <iostream>
#include <stack> // include your own version of stack, it is important to support
				 // push, pop, top, empty methods

//example :
//532*+ <-> 5 + (3 * 2)
//answer is : 11

inline bool is_operator(char c) {
	
	return (c == '+') || (c == '-') || 
		   (c == '*') || (c == '/');
}

double calc(char op, double left, double right) {
	
	switch (op) {

		case '+': return  left + right;
		case '-': return  left - right;
		case '*': return left * right;
		case '/': return left / right;
		default : return -1.0;
	}
}

int main() {
	
	std::stack<double> calculator;
	
	char buffer[1024];
	
	std::cin.getline(buffer, 1024);
		
	int i = 0;
	double left, right;
	
	while (buffer[i] != '\0') {
		
		if (isdigit(buffer[i])) {

			calculator.push(double(buffer[i] - '0')); //ascii -> double
			i++;
			continue;
		}
		
		if (is_operator(buffer[i])) {
	
			if (calculator.size() < 2) { // not enough operands
				std::cout << "wrong input!" << std::endl;
				return 1;
			}
			// take the two operands
			right = calculator.top();
			calculator.pop();
			left = calculator.top();
			calculator.pop();
			// push the result
			calculator.push(calc(buffer[i], left, right));
		}
		i++;
	}
	// the result should be the last number at the stack
	double res = calculator.top();
	calculator.pop();
	
	if (calculator.empty()) // the stack should be empty if everything is alright
		std::cout << "answer is : " << res << std::endl;
	else 
		std::cout << "wrong input!" << std::endl;
		
	return 0;
}
