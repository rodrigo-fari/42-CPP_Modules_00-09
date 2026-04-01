/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 23:15:45 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << YELLOW << "\n=== Testing Bureaucrat Class ===" << RESET << std::endl << std::endl;

	// Test 1: Valid bureaucrat
	std::cout << BLUE << "Test 1: Creating valid bureaucrat" << RESET << std::endl;
	try
	{
		Bureaucrat b1("Alice", 75);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Grade too high (< 1)
	std::cout << BLUE << "Test 2: Creating bureaucrat with grade too high (0)" << RESET << std::endl;
	try
	{
		Bureaucrat b2("Bob", 0);
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Grade too low (> 150)
	std::cout << BLUE << "Test 3: Creating bureaucrat with grade too low (151)" << RESET << std::endl;
	try
	{
		Bureaucrat b3("Charlie", 151);
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Increase grade
	std::cout << BLUE << "Test 4: Increasing grade" << RESET << std::endl;
	try
	{
		Bureaucrat b4("David", 2);
		std::cout << b4 << std::endl;
		b4.increaseGrade();
		std::cout << b4 << std::endl;
		b4.increaseGrade(); // Should throw exception
		std::cout << b4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Decrease grade
	std::cout << BLUE << "Test 5: Decreasing grade" << RESET << std::endl;
	try
	{
		Bureaucrat b5("Eve", 149);
		std::cout << b5 << std::endl;
		b5.decreaseGrade();
		std::cout << b5 << std::endl;
		b5.decreaseGrade(); // Should throw exception
		std::cout << b5 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "=== All tests completed ===" << RESET << std::endl;
	return (0);
}