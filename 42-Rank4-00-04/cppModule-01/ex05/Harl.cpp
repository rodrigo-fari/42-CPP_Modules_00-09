/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:02:14 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/07 17:59:00 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "[HARL] Debug message." << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[HARL] Info message." << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[HARL] Warning message." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[HARL] Error message." << std::endl;
}

void	Harl::complain( std::string level ) {
	for(size_t i = 0; level[i]; i++) {
		level[i] = toupper(level[i]);
	}

	void	(Harl::*functionList[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string harlMessage[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for(int i = 0; i < 4; i++) {
		if (harlMessage[i] == level) {
			(this->*functionList[i])();
			return ;
		}
	}

	std::cout << "Probably harl is complaining about insignificant problems. lol" << std::endl;
}
