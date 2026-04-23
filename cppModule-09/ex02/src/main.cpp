/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:37:37 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/23 16:19:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av)
		return ((std::cerr << "Error: Invalid program usage.\n Try: ./PmergeMe \"agr1 arg2 ...\"" << std::endl), 1);

	PmergeMe a;

	try {
	
		std::vector<int> argsVect = stringToIntVector(av[1]);
		a.setVectorValues(argsVect); a.printVectorValues();
	
	} catch(std::exception& e) {
	
		std::cerr << e.what() << std::endl;
		return (MAIN_ERROR);
	}
	//*|-------------------------------| DEBUG AREA |
	std::cout << "==| Success! |==" << std::endl;
	system("make fclean"); //! APENAS PRA DEBUG; NAO ESQUECER DE REMOVER POSTERIORMENTE!
	return (MAIN_SUCCESS);
}
