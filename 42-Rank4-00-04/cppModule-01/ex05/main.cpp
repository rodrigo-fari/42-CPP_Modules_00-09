/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:02:27 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/07 17:56:24 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void ) {
	{
		Harl	harl;
		std::string possibleMessages[5] = {
			"eRrOr",
			"WarNinG",
			"DebUg",
			"INFo",
			"Rodrigo :D"
		};

		for (int i = 0; i < 5; i++) {
			harl.complain(possibleMessages[i]);
		}

		return (0);
	}
}
