/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:51:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/25 00:33:06 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137) , target(target)
{
	std::cout << "📝: ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
	: AForm(original), target(original.target)
{
	std::cout << "📝: ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	std::cout << "📝: ShrubberyCreationForm copy assignement operator called." << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "📝: ShrubberyCreationForm destructor called." << std::endl;
}

const char *ShrubberyCreationForm::UnableToOpenFileException::what() const throw()
{
	return ("Error: Unable to open target file.");
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file;
	file.open((this->target + "_shrubbery").c_str(), std::ios::out);
	
	if (file.fail())
		throw UnableToOpenFileException();
	std::cout << "Growing a tree for 🫵 C:\n";

	std::string sakuraTree = 
		"        / OOOOOO                               /\n"
		"       /OOOOOOOOO    OOOOOOO                  /\n"
		" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO           /\n"
		" OOOOOOOOOOOOO\\OO/OOOOOOOOOOOOOOOOOO        /\n"
		"OOOOOOOOOOOOO\\ \\/ /OOOOOOOOOOOOOOOOO       /\n"
		"OOOO\\ /OOOOOOO\\  /  OO O OO\\ /OOOOOO      /\n"
		" OO\\ v /OOO    | |        \\ v /O         /\n"
		"  / | |        | |        |  |          /\n"
		" /  |.|        | |        |  |         /\n"
		"/_____________________________________/\n";

	file << sakuraTree;
	file.close();
}