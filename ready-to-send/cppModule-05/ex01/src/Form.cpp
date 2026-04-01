/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:20:09 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 23:18:55 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _signed(false), _gradeToSign(10), _gradeToExec(50)
{
	std::cout << "📝: Default constructor called." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	:_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "📝: Param constructor called." << std::endl;
	if (gradeToExec < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& original)
	:_name(original._name), _signed(original._signed),
	_gradeToSign(original._gradeToSign), _gradeToExec(original._gradeToExec)
{
	std::cout << "📝: Copy operator called." << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "📝: Copy assignement operator called." << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "📝: Destructor called." << std::endl;
}

std::string	Form::getName() const
{
	return(this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bcrat)
{
	if (bcrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	if (this->_signed == 1)
		throw FormAlreadySignedException();
	std::cout << GREEN << bcrat.getName() << " signed " << this->getName() << RESET << std::endl;
	this->_signed = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("form is already signed!");
}

std::ostream &operator<<(std::ostream &out, const Form& form)
{	
	out << YELLOW
		<< std::endl
		<< "====== Form's info ======"<< std::endl
		<< "Name: " << form.getName() << std::endl
		<< "Is signed: " << (form.getSigned() ? "TRUE" : "FALSE") << std::endl
		<< "Minimum grade to sign: " << form.getGradeToSign() << std::endl
		<< "Minimum grade to execute: " << form.getGradeToExec() << std::endl
		<< "========================="
		<< RESET
		<< std::endl;
	return (out);
}