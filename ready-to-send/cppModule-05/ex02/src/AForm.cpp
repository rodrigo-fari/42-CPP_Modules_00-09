/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:20:09 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 22:46:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _gradeToSign(10), _gradeToExec(50)
{
	std::cout << "📝: Default constructor called." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
	:_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "📝: Param constructor called." << std::endl;
	if (gradeToExec < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& original)
	:_name(original._name), _signed(original._signed),
	_gradeToSign(original._gradeToSign), _gradeToExec(original._gradeToExec)
{
	std::cout << "📝: Copy operator called." << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	std::cout << "📝: Copy assignement operator called." << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "📝: Destructor called." << std::endl;
}

std::string	AForm::getName() const
{
	return(this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat& bcrat)
{
	if (bcrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	if (this->_signed == 1)
		throw FormAlreadySignedException();
	std::cout << GREEN << bcrat.getName() << " signed " << this->getName() << RESET << std::endl;
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() < 1)
		throw GradeTooHighException();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw FormNotSignedYetException();
	this->executeAction();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return ("form is already signed!");
}

const char *AForm::FormNotSignedYetException::what() const throw()
{
	return ("form needs to be signed before execution!");
}

std::ostream &operator<<(std::ostream &out, const AForm& form)
{	
	out << YELLOW
		<< std::endl
		<< "====== AForm's info ======"<< std::endl
		<< "Name: " << form.getName() << std::endl
		<< "Is signed: " << (form.getSigned() ? "TRUE" : "FALSE") << std::endl
		<< "Minimum grade to sign: " << form.getGradeToSign() << std::endl
		<< "Minimum grade to execute: " << form.getGradeToExec() << std::endl
		<< "========================="
		<< RESET
		<< std::endl;
	return (out);
}