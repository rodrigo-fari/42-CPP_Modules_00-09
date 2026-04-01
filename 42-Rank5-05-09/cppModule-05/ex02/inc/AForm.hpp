/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:31:52 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 22:46:21 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;

public:
	// Orthodox Canonical AForm
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm& original);
	AForm &operator=(const AForm &rhs);
	~AForm();

	// Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	// Member function
	void beSigned(const Bureaucrat& bcrat);
	void execute(const Bureaucrat& executor) const;
	virtual void executeAction() const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class FormNotSignedYetException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

// Operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif