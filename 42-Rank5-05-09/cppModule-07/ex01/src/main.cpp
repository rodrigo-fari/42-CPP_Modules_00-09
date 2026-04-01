/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:43:45 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 13:59:44 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
	std::string strings[] = {"str1", "str2", "str3", "str4", "str5", "str6", "str7", "str8", "str9", "str10"};
	float floats[] = {0.2, 1.4, 1.7, 2.1, 2.5};
	int numbers[]= {02, 14, 17, 21, 25};

	std::cout << "--- Testing iter ---" << std::endl << std::endl;

	std::cout << "With Strings" << std::endl;
	iter(strings, 5, printMsg);
	std::endl(std::cout);

	std::cout << "With Floats" << std::endl;
	iter(floats, 5, printMsg);
	std::endl(std::cout);

	std::cout << "With Integers" << std::endl;
	iter(numbers, 5, printMsg);
	std::endl(std::cout);

	std::cout << "Test both iter functions (const and non-const)" << std::endl;
	int array[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(array) / sizeof(array[0]);

	iter(array, length, printMsg);

	const int constArray[] = {6, 7, 8, 9, 10};
	length = sizeof(constArray) / sizeof(constArray[0]);

	iter(constArray, length, static_cast<void(*)(const int&)>(printMsg));

	return (0);
}
