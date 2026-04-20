/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:47:23 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/20 18:32:24 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//-------------------------------------| OCF DECLARATION |

RPN::RPN() { }

RPN::RPN(const RPN& other) : _intStack(other._intStack) { }

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_intStack = other._intStack;
	}
	return (*this);
}

RPN::~RPN() { }

//-------------------------------------| MEMBER FUNCTIONS DECLARATION

int		RPN::calculate(const std::string& expression) {
	
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (isMathematicalOperator(token))
			operationCore(token);
		else
		{
			if (token.length() != 1 || !isdigit(token[0]))
				throw std::runtime_error("Error");
			int num = std::atoi(token.c_str());
			_intStack.push(num);
		}
	}
	if(_intStack.size() != 1)
		throw std::runtime_error("Error");

	int result = _intStack.top();

	_intStack.pop();

	return(result);
}

bool	RPN::isMathematicalOperator(const std::string& token) {
	return (token == "+"
		|| token == "-"
		|| token == "*"
		|| token == "/");
}

void	RPN::operationCore(const std::string& mathOperator) {
	if (_intStack.size() < 2)
		throw std::runtime_error("Error");
	int right = _intStack.top();
	_intStack.pop();
	int left = _intStack.top();
	_intStack.pop();

	int result = 0;

	if (mathOperator == "+")
		result = left + right;
	else if (mathOperator == "-")
		result = left - right;
	else if (mathOperator == "*")
		result = left * right;
	else if (mathOperator == "/")
	{
		if (right == 0)
			throw std::runtime_error("Error");
		result = left / right;
	}

	_intStack.push(result);
}

//-------------------------------------| CUSTOM EXCEPTION DECLARATION

const char* RPN::InvalidOperationException::what() const throw() {
	return ("Error: Invalid operation.");
}