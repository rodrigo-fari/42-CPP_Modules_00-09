/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:15 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 23:15:31 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(10)
{
	std::cout << "🎩: Default constructor called." << std::endl;
}

// Param constructor
Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	std::cout << "🎩: Param constructor called." << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &original)
	: _name(original._name), _grade(original._grade)
{
	std::cout << "🎩: Copy constructor called." << std::endl;
}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "🎩: Copy assignment operator called." << std::endl;
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "🎩: Destructor called" << std::endl;
}

// Getters
const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

// Member functions
void Bureaucrat::increaseGrade()
{
	std::cout << "Increasing " << BLUE << getName() << RESET << " grade." << std::endl;
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	std::cout << "Decreasing " << BLUE << getName() << RESET << " grade." << std::endl;
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// Exception implementations
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high!");
}

// Operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << GREEN << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << RESET;
	return (out);
}
