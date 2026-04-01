/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:20:31 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 21:11:38 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"


const char* EmptyContainerException::what() const throw()
{
	return ("Error: Container is empty!");
}

const char* NumberDoesNotExistsException::what() const throw()
{
	return ("Error: Number does not exists in container!");
}

static void enter_to_continue()
{
	std::cout << "\n\nPress |ENTER| to continue" << std::endl;
	std::cin.get();
	system("clear");
}

static void TestWithVector()
{
	std::vector<int> vec;

	try
	{
		std::cout << "Testing with empty vector:\n";
		std::cout << Green << easyfind(vec, 10) << Reset << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << Red << e.what() << Reset << std::endl;
	}
	
	enter_to_continue();
	
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	std::cout << Yellow << "Testing with a vector of integers" << Reset << std::endl;
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	try
	{
		std::cout << "Searching for 5: ";
		std::cout << Green << easyfind(vec, 5) << Reset << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << Red << e.what() << Reset << std::endl;
	}
		
	try
	{
		std::cout << "Searching for 10: ";
		std::cout << Green << easyfind(vec, 10) << Reset << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << Red << e.what() << Reset << std::endl;
	}
	
	enter_to_continue();

}

int main()
{
	TestWithVector();
	return (0);
}
