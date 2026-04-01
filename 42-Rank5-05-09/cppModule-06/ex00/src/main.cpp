/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/17 12:41:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return ((std::cerr << "[ERROR: Invalid usage.]\nUsage: ./ex00 <Only one argument>.\n"), 1);
	std::string inputData = av[1];
	ScalarConverter::convert(inputData);
}
