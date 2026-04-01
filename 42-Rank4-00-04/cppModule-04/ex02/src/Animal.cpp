/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:58:44 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 17:10:45 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "🐾: Animal default constructor called." << std::endl;
	this->_type = "General Animal";
}

Animal::Animal(const Animal &main)
{
	std::cout << "🐾: Animal copy constructor called." << std::endl;
	this->_type = main._type;
}

Animal::~Animal()
{
	std::cout << "🐾: Animal default destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "🐾: Animal copy assignment constructor called." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void msg(std::string msg)
{
	std::cout << std::endl
			<< "    ℹ️  "
			<< msg
			<< "  ℹ️"
			<< std::endl
			<< std::endl;
}