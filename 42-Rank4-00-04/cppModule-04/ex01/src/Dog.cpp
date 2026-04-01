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
	this->_brain = new Brain;
	std::cout << "🐕: Dog default constructor called." << std::endl;
}

Dog::~Dog() {
	delete(this->_brain);
	std::cout << "🐕: Dog destructor called." << std::endl;
}

Dog::Dog(const Dog& main) : Animal(main) {
	std::cout << "🐕: Dog copy constructor called." << std::endl;
	this->_type = main._type;
	this->_brain = new Brain(*main._brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "🐕: Dog copy assignment operator called. " << std::endl;
	if (this != &other) {
		this->_type = other._type;
		delete(this->_brain);
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "🐕: Oof Oof - (Doggy sounds)." << std::endl;
}

Brain& Dog::getBrain() const {
	return *this->_brain;
}
