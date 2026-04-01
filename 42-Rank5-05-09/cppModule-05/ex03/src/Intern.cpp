/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:06:06 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/01 15:32:57 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	funcArray[0] = &Intern::Presidential;
	funcArray[1] = &Intern::Shrubbery;
	funcArray[2] = &Intern::Robotomy;
}

AForm* Intern::Presidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::Shrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::Robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

Intern::~Intern(void){}

const char* Intern::NoFormException::what() const throw()
{
	return("Form not found.");
}

AForm* Intern::makeForm(std::string formName, std::string target) {

	std::string forms[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};	

	for(int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
			return (this->*funcArray[i])(target);
	}
	throw Intern::NoFormException();
}
