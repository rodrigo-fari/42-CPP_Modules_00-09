/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:51:48 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/01 19:28:42 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int ac, char **av) {
	if (validateArguments(ac, av) == ERRO)
		return(ERRO);
	FileReplacer	instance;
	setInfo(instance, av);
	if (searchAndReplace(instance) == ERRO)
		return (ERRO);
	std::cout << GREEN << "[ ✓ ] " << RESET << av[1] << ".replace created successfully!" << std::endl;
	return (SUCCESS);
}
