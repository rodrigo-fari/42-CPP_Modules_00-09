/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:50:45 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/13 20:16:58 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "⭕🐈: WrongCat default constructor called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "⭕🐈: WrongCat default destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal() {
	std::cout << "⭕🐈: WrongCat copy operator called." << std::endl;
	this->_type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "⭕🐈: WrongCat copy assignment operator called. " << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "⭕🐈: Miau - (Kitty sounds)." << std::endl;
}