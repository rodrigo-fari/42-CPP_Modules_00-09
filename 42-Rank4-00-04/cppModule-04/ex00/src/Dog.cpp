	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:50:47 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/30 12:58:26 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "🐕: Dog default constructor called." << std::endl;
}

Dog::~Dog() {
	std::cout << "🐕: Dog default destructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal() {
	std::cout << "🐕: Dog copy operator called." << std::endl;
	this->_type = other._type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "🐕: Dog copy assignment operator called. " << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "🐕: Oof Oof - (Doggy sounds)." << std::endl;
}