/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:58:44 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/13 20:16:45 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "⭕🐾: WrongAnimal default constructor called." << std::endl;
	this->_type = "General WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "⭕🐾: WrongAnimal copy constructor called." << std::endl;
	this->_type = other._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "⭕🐾: WrongAnimal default destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "⭕🐾: WrongAnimal copy assignment constructor called." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "⭕🐾: *Default WrongAnimal sound.*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}
