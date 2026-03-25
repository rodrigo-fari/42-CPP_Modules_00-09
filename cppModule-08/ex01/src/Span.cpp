/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:18:12 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/25 14:50:57 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) { }

Span::Span( unsigned int number ) : _n( number ) { }

Span& Span::operator=( const Span& other ) {
	if ( this != &other )
		this->numberVector = other.numberVector;
	return ( *this );	
}

Span::~Span() { }

void Span::addNumber( unsigned int number ) {
	
}

unsigned int Span::shortestSpan() {
	
}

unsigned int Span::longestSpan() {
	
}

const char* Span::OutOfBoundesException::what() const throw() {
	return ( "Error: Out of bounds!" );
}

std::ostream& operator<<(std::ostream out, const Span& rhs) {
	//retorna talvez o vetor, ou o limite determinado por N
}