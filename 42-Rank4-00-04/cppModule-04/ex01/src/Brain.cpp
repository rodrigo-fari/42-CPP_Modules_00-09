/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:22:40 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 01:53:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "🧠: Brain default constructor called." << std::endl;
}

Brain::Brain( const Brain& main ) {
	std::cout << "🧠: Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = main._ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "🧠: Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "🧠: Brain copy assignment operator called. " << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string idea) {
	this->_ideas[index] = idea;
}

std::string& Brain::getIdea(int index) {
	return this->_ideas[index];
}
