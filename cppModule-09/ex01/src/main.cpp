/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:56:57 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/20 18:27:54 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av)
		return ((std::cerr << "Error: Invalid usage. \n Try: ./RPN \"args\".\n"), 1);
	
	RPN calculator;
	
	try {
		
		int result = calculator.calculate(av[1]);
		std::cout << result << std::endl;
	
	} catch (const std::exception& e) {
	
		std::cerr << e.what() << std::endl;
		return (1);
	
	}
	return (0);
}
