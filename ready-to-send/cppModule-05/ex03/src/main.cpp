/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/01 15:35:40 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void enter_to_continue()
{
	std::cout << "\n\nPress |ENTER| to continue" << std::endl;
	std::cin.get();
	system("clear");
}

static void testMakeForms()
{
	try
	{
		Intern intern;
		AForm *f1 = intern.makeForm("presidential pardon", "target1");
		std::cout << *f1 << std::endl;
		Bureaucrat b1("b1", 4);
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		AForm *f2 = intern.makeForm("shrubbery creation", "target2");
		std::cout << *f2 << std::endl;
		Bureaucrat b2("b2", 132);
		b2.signForm(*f2);
		b2.executeForm(*f2);
		delete f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		AForm *f3 = intern.makeForm("robotomy request", "target3");
		std::cout << *f3 << std::endl;
		Bureaucrat b3("b3", 40);
		b3.signForm(*f3);
		b3.executeForm(*f3);
		delete f3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	testMakeForms();
	enter_to_continue();
}