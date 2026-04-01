/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/25 00:46:21 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	{
		std::cout << YELLOW << "\n=== Testing Bureaucrat & Forms ===" << RESET << std::endl << std::endl;

		try {
			std::cout << BLUE << "Test 1: ShrubberyCreationForm" << RESET << std::endl;
			Bureaucrat b1("Alice", 1);
			ShrubberyCreationForm f1("garden");
			std::cout << std::endl << b1 << std::endl;
			std::cout << f1 << std::endl;
			b1.signForm(f1);
			b1.executeForm(f1);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << BLUE << "Test 2: RobotomyRequestForm" << RESET << std::endl;
			Bureaucrat b2("Bob", 40);
			RobotomyRequestForm f2("Bender");
			std::cout << std::endl << b2 << std::endl;
			std::cout << f2 << std::endl;
			b2.signForm(f2);
			b2.executeForm(f2);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << BLUE << "Test 3: PresidentialPardonForm" << RESET << std::endl;
			Bureaucrat b3("Charlie", 1);
			PresidentialPardonForm f3("Arthur Dent");
			std::cout << std::endl << b3 << std::endl;
			std::cout << f3 << std::endl;
			b3.signForm(f3);
			b3.executeForm(f3);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << YELLOW << "\n=== Testing Bureaucrat & Forms ===" << RESET << std::endl << std::endl;

		try {
			std::cout << BLUE << "Test 1 Wrong: ShrubberyCreationForm" << RESET << std::endl;
			Bureaucrat b1("Alice", 150);
			ShrubberyCreationForm f1("garden");
			std::cout << std::endl << b1 << std::endl;
			std::cout << f1 << std::endl;
			b1.signForm(f1);
			b1.executeForm(f1);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << BLUE << "Test 2 Wrong: RobotomyRequestForm" << RESET << std::endl;
			Bureaucrat b2("Bob", 150);
			RobotomyRequestForm f2("Bender");
			std::cout << std::endl << b2 << std::endl;
			std::cout << f2 << std::endl;
			b2.signForm(f2);
			b2.executeForm(f2);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << BLUE << "Test 3 Wrong: PresidentialPardonForm" << RESET << std::endl;
			Bureaucrat b3("Charlie", 6);
			PresidentialPardonForm f3("Arthur Dent");
			std::cout << std::endl << b3 << std::endl;
			std::cout << f3 << std::endl;
			b3.signForm(f3);
			b3.executeForm(f3);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << YELLOW << "=== All tests completed ===" << RESET << std::endl;
	return (0);
}