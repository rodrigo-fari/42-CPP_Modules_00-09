/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:40:40 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 13:52:04 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void wait_seconds(int sec) {
	time_t start = time(NULL);
	while (time(NULL) - start < sec)
		;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << CLEAR_SCREEN
				<< "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl
				<< "┃      P   H   O   N   E   B   O   O   K     ┃" << std::endl
				<< "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl
				<< std::endl
				<< "[ 1 ] Add contact." << std::endl
				<< std::endl
				<< "[ 2 ] Search contact." << std::endl
				<< std::endl
				<< "[ 3 ] Exit PhoneBook." << std::endl
				<< std::endl
				<< "[Command]: ";
		if (!std::getline(std::cin, command)) {
			std::cout << CLEAR_SCREEN;
			break;
		}
		if (command == "1" || command == "add" || command == "ADD")
			phoneBook.addContact();
		else if (command == "2" || command == "search" || command ==  "SEARCH")
			phoneBook.searchContact();
		else if (command == "3" || command == "exit" || command == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	std::cout << CLEAR_SCREEN;
	return 0;
}
