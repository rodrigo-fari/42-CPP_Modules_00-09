/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:18:12 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/26 15:34:47 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) { }

Span::Span(unsigned int number) : _n(number) { }

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_n = other._n;
		this->_numberVector = other._numberVector;
	}
	return (*this);	
}

Span::~Span() { }

void Span::addNumber(unsigned int number) {
	if (this->_numberVector.size() == this->_n)
		throw OutOfBoundesException();
	else
		this->_numberVector.push_back(number);
}

unsigned int Span::shortestSpan() {
	if (this->_numberVector.empty())
		throw NoNumbersFoundException();
	if (this->_numberVector.size() < 2)
		throw NoSpanFoundException();

	std::vector<unsigned int> sorted = this->_numberVector;
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		unsigned int current = sorted[i + 1] - sorted[i];
		if (current < shortest)
			shortest = current;
	}
	return (shortest);
}

unsigned int Span::longestSpan() {
	if (this->_numberVector.empty())
		throw NoNumbersFoundException();
	if (this->_numberVector.size() < 2)
		throw NoSpanFoundException();

	unsigned int min;
	unsigned int max;
	
	min = *std::min_element(this->_numberVector.begin(), this->_numberVector.end());
	max = *std::max_element(this->_numberVector.begin(), this->_numberVector.end());
	
	return (max - min);
}

const char* Span::OutOfBoundesException::what() const throw() {
	return ("Error: Out of bounds!");
}

const char* Span::NoSpanFoundException::what() const throw() {
	return ("Error: Not enough numbers to find a span!");
}

const char* Span::NoNumbersFoundException::what() const throw() {
	return ("Error: No numbers found!");
}
