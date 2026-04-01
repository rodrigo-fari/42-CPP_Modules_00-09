/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:35:06 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/29 16:30:56 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_count = 0;
	_nextIndex = 0;
}

static int cppAtoi(const std::string& str) {
	std::istringstream iss(str);
	int num = 0;
	iss >> num;
	return (num);
}

void	PhoneBook::addContact() {
	Contact	newContact;
	newContact.setInfo();
	if (newContact.isEmpty()) {
		std::cout << CLEAR_SCREEN;
		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
		std::cout << "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl;
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
		std::cout << std::endl;
		std::cout << "[ ✗ ] All fields are required!" << std::endl;
		wait_seconds(3);
		return ;
	}
	_contacts[_nextIndex] = newContact;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_count < 8)
		_count++;
	std::cout << CLEAR_SCREEN;
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
	std::cout << "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
	std::cout << std::endl;
	std::cout << "[ ✓ ] Contact added successfully!" << std::endl;
	wait_seconds(3);
}

void	PhoneBook::searchContact() {
	if (_count == 0) {
		std::cout << CLEAR_SCREEN;
		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
		std::cout << "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl;
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
		std::cout << std::endl;
		std::cout << "[ ✗ ] PhoneBook is empty!" << std::endl;
		wait_seconds(3);
		return ;
	}
	std::cout << CLEAR_SCREEN;
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
	std::cout << "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl;
	std::cout << "┣━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━━┫" << std::endl;
	std::cout << "┃" << std::setw(10) << "Index" << "┃"
			<< std::setw(10) << "First Name" << "┃"
			<< std::setw(10) << "Last Name" << "┃"
			<< std::setw(10) << "Nickname" << " ┃" <<std::endl;
	for( int i = 0; i < _count; i++) {
		std::cout << "┣━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━━┫" << std::endl;
		_contacts[i].displayShort(i);
	}
	std::cout << "┗━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━━┛" << std::endl;
	std::string input;
	std::cout << "[Index]: ";
	std::getline(std::cin, input);
	try {
			int	index = cppAtoi(input);
			if (index < 1 || index > _count) {
			std::cout << CLEAR_SCREEN;
			std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
			std::cout << "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl;
			std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
			std::cout << std::endl;
			std::cout << "[ ✗ ] Invalid index!" << std::endl;
			wait_seconds(3);
			return ;
		}
		_contacts[index - 1].displayFull();
	} catch (const std::exception &e) {
		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
		std::cout << "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl;
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
		std::cout << std::endl;
		std::cout << "[ X ] Invalid index!" << std::endl;
	}
}
