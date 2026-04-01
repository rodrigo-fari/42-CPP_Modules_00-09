/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:24:18 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 17:05:47 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) { 
	std::cout <<  "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNbr) {
	std::cout <<  "Int constructor called" << std::endl;
	this->_fixedPoint = (intNbr << this->_fracBits);
}

Fixed::Fixed(const float floatNbr) {
	std::cout <<  "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floatNbr * (1 << this->_fracBits));
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPoint = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( const int raw ) {
	std::cout << "getRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

int		Fixed::toInt( void ) const {
	return (this->_fixedPoint >> _fracBits);
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(this->_fixedPoint) / (1 << this->_fracBits));
}

//Overload do operador "<<".
std::ostream& operator<<(std::ostream& os, Fixed const& rhs) {
	os << rhs.toFloat();
	return (os);
}

