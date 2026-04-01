/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:24:18 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 17:12:00 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) { 
}

Fixed::Fixed(const int intNbr) {
	this->_fixedPoint = (intNbr << this->_fracBits);
}

Fixed::Fixed(const float floatNbr) {
	this->_fixedPoint = roundf(floatNbr * (1 << this->_fracBits));
}

Fixed::Fixed( const Fixed& other ) {
	*this = other;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	if (this != &other) {
		this->_fixedPoint = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits( void ) const {
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( const int raw ) {
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

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const { return this->_fixedPoint > other._fixedPoint; }

bool Fixed::operator<(const Fixed& other) const { return this->_fixedPoint < other._fixedPoint; }

bool Fixed::operator>=(const Fixed& other) const { return this->_fixedPoint >= other._fixedPoint; }

bool Fixed::operator<=(const Fixed& other) const { return this->_fixedPoint <= other._fixedPoint; }

bool Fixed::operator==(const Fixed& other) const { return this->_fixedPoint == other._fixedPoint; }

bool Fixed::operator!=(const Fixed& other) const { return this->_fixedPoint != other._fixedPoint; }

Fixed& Fixed::operator++() {
	this->_fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPoint++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPoint--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}